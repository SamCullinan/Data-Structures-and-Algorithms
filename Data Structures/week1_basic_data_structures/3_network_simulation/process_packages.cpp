#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
        size_(size),
        finish()
    {}

    Response Process(const Request &request) {
        
        Response res(false, 0);
        if(finish.empty()){
            res.start_time = request.arrival_time;
            finish.push(request.arrival_time + request.process_time);
        }
        else{
            
            while(!finish.empty()){
                if(request.arrival_time >= finish.front())
                    finish.pop();
                else{
                    
                    if(finish.size() == size_){
                        res.start_time = 0;
                        res.dropped = true;
                    }
                    
                    else if(finish.size() < size_){
                        res.start_time = finish.back();
                        finish.push(res.start_time + request.process_time);
                    }
                    
                    break;
                }
            }
            
            if(finish.empty()){
                res.start_time = request.arrival_time;
                finish.push(request.arrival_time + request.process_time);
            }
        }
        return res;
    }
    
private:
    int size_;
    queue<int> finish;
};

vector <Request> ReadRequests() {
    vector <Request> requests;
    int count;
    cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    
    return requests;
}

vector <Response> ProcessRequests(const vector <Request> &requests, Buffer *buffer) {
    vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    
    return responses;
}

void PrintResponses(const std::vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
    int size;
    cin >> size;
    vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
