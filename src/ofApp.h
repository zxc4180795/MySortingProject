#pragma once

#include "ofMain.h"
#include <vector>
#include <random>
#include <algorithm>

class ofApp : public ofBaseApp {
private:
    std::vector<int> numbers;
    const int NUM_CIRCLES = 5;
    const int MIN_VALUE = 10;
    const int MAX_VALUE = 100;
    const float CIRCLE_SPACING = 150;
    const float CIRCLE_Y = 300;
    const float START_X = 200;

    void generateRandomNumbers();
    void bubbleSort();
    void insertionSort();
    void merge(int left, int mid, int right);
    void mergeSortHelper(int left, int right);
    void mergeSort();
    int partition(int low, int high);
    void quickSortHelper(int low, int high);
    void quickSort();
    void fisherYatesShuffle();

public:
    void setup();
    void draw();
    void keyPressed(int key);
};