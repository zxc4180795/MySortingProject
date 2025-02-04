#include "ofApp.h"

void ofApp::setup() {
    ofSetBackgroundColor(0);
    generateRandomNumbers();
}

void ofApp::draw() {
    ofSetBackgroundColor(0);

    for (int i = 0; i < numbers.size(); i++) {
        float x = START_X + i * CIRCLE_SPACING;
        float radius = numbers[i] * 0.5;

        ofSetColor(8, 255, 0);
        ofFill();
        ofDrawCircle(x, CIRCLE_Y, radius);

        ofSetColor(0);
        string numStr = ofToString(numbers[i]);
        ofDrawBitmapString(numStr, x - 10, CIRCLE_Y);
    }
}

void ofApp::keyPressed(int key) {
    switch (key) {
    case 'r':
        generateRandomNumbers();
        break;
    case 'b':
        bubbleSort();
        break;
    case 'i':
        insertionSort();
        break;
    case 'm':
        mergeSort();
        break;
    case 'q':
        quickSort();
        break;
    case 's':
        fisherYatesShuffle();
        break;
    }
}

// Generate random numbers
void ofApp::generateRandomNumbers() {
    numbers.clear();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(MIN_VALUE, MAX_VALUE);

    for (int i = 0; i < NUM_CIRCLES; i++) {
        numbers.push_back(dis(gen));
    }
}

// Bubble sort
void ofApp::bubbleSort() {
    int n = numbers.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                std::swap(numbers[j], numbers[j + 1]);
            }
        }
    }
}

// Insertion sort
void ofApp::insertionSort() {
    int n = numbers.size();
    for (int i = 1; i < n; i++) {
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
    }
}

// Merge sort helper function
void ofApp::merge(int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (numbers[i] <= numbers[j]) {
            temp[k++] = numbers[i++];
        }
        else {
            temp[k++] = numbers[j++];
        }
    }

    while (i <= mid) temp[k++] = numbers[i++];
    while (j <= right) temp[k++] = numbers[j++];

    for (i = 0; i < k; i++) {
        numbers[left + i] = temp[i];
    }
}

// Merge sort
void ofApp::mergeSortHelper(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(left, mid);
        mergeSortHelper(mid + 1, right);
        merge(left, mid, right);
    }
}

void ofApp::mergeSort() {
    mergeSortHelper(0, numbers.size() - 1);
}

// Quick sort helper function
int ofApp::partition(int low, int high) {
    int pivot = numbers[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (numbers[j] <= pivot) {
            i++;
            std::swap(numbers[i], numbers[j]);
        }
    }
    std::swap(numbers[i + 1], numbers[high]);
    return i + 1;
}

// Quick sort
void ofApp::quickSortHelper(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSortHelper(low, pi - 1);
        quickSortHelper(pi + 1, high);
    }
}

void ofApp::quickSort() {
    quickSortHelper(0, numbers.size() - 1);
}

// Fisher-Yates shuffle algorithm
void ofApp::fisherYatesShuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = numbers.size() - 1; i > 0; i--) {
        std::uniform_int_distribution<> dis(0, i);
        int j = dis(gen);
        std::swap(numbers[i], numbers[j]);
    }
}