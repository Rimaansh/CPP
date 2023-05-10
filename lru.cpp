#include <iostream>
const int max = 2147483647;
using namespace std;

void lru(int pages[], int num_pages, int num_frames) {
    int frame[num_frames], recent[num_pages], time = 0;
    int faults = 0;

    for (int i = 0; i < num_frames; i++) 
    {
        frame[i] = -1;
        recent[i] = -1;
    }

    for (int i = 0; i < num_pages; i++) 
    {
        int page_found = 0, replace = 0;
        for (int j = 0; j < num_frames; j++) 
        {
            if (frame[j] == pages[i]) 
            {
                page_found = 1;
                recent[j] = time++;
                break;
            }
        }
        if (!page_found) 
        {
            int oldest = INT_MAX;
            for (int j = 0; j < num_frames; j++) 
            {
                if (recent[j] < oldest) {
                    oldest = recent[j];
                    replace = j;
                }
            }
            frame[replace] = pages[i];
            recent[replace] = time++;
            faults++;
        }
        // cout << "Page " << pages[i] << " : ";
        // for (int j = 0; j < num_frames; j++) {
        //     if (frame[j] == -1)
        //         cout << "-- ";
        //     else
        //         cout << frame[j] << " ";
        // }
        // cout << endl;
    }
    cout << "Number of page faults: " << faults << endl;
}

int main() {
    int num_frames, num_pages;
    cout << "Enter the number of frames available: ";
    cin >> num_frames;
    cout << "Enter the number of pages: ";
    cin >> num_pages;
    int pages[num_pages];
    cout << "Enter the pages: ";
    for (int i = 0; i < num_pages; i++) {
        cin >> pages[i];
    }
    lru(pages, num_pages, num_frames);
    return 0;
}
// 4
// 20
// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1