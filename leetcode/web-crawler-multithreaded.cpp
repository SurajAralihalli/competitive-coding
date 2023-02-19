// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/web-crawler-multithreaded/description/
// Date: 19th Feb, 2023
// Tags: concurrency, thread, mutex

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

unordered_set<string> crawled;
queue<string> tasks;
int working_threads;
bool done;
pthread_mutex_t mutex_lock;
pthread_cond_t cv;

bool areSameHostname(string a, string b) {
    stringstream ss(a);
    string tokenA = "";
    for(int i=0;i<3;i++)
    {
        getline(ss, tokenA, '/');
    }

    stringstream ss2(a);
    string tokenB = "";
    for(int i=0;i<3;i++)
    {
        getline(ss2, tokenB, '/');
    }

    return tokenA == tokenB;
}

void* parallel_crawl(void* hp) {
        while(true) {
            pthread_mutex_lock(&mutex_lock);
            while( tasks.empty() && !done ) {
                cout << "here" << endl;
                pthread_cond_wait(&cv, &mutex_lock);
            }

            if(done) {
                cout << "exit" << endl;
                pthread_cond_broadcast(&cv);
                pthread_mutex_unlock(&mutex_lock);
                return NULL;
            }

            working_threads++;
            string host_url = tasks.front(); tasks.pop();
            cout << host_url << endl;
            pthread_cond_signal(&cv);
            pthread_mutex_unlock(&mutex_lock);

            HtmlParser* hParser = (HtmlParser*) hp;
            auto urls = hParser->getUrls(host_url);

            pthread_mutex_lock(&mutex_lock);
            for(auto url: urls) {
                if(areSameHostname(url, host_url) && crawled.count(url)==0) {
                    tasks.push(url);
                    crawled.insert(url);
                }
            }
            
            working_threads--;
            if(tasks.empty() && working_threads==0) {
                done = true;
                cout << "done" << endl;
            }
            pthread_cond_broadcast(&cv);
            pthread_mutex_unlock(&mutex_lock);
        }
    }



class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {

        pthread_mutex_init(&mutex_lock, NULL);
        pthread_cond_init(&cv, NULL);
        working_threads = 0;
        crawled.insert(startUrl);
        tasks.push(startUrl);
        done = false;
        
        unsigned int n = std::thread::hardware_concurrency();

        pthread_t threads[n];
        for(auto worker: threads) {
            pthread_create(&worker, NULL, parallel_crawl, &htmlParser);
        }

        for(auto worker: threads) {
            pthread_join(worker, NULL);
        }

        return vector<string> (crawled.begin(), crawled.end());
    }
};
