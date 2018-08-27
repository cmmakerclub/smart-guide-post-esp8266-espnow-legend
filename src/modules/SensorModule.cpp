#include "SensorModule.h"

void swap(float &a, float &b)
{
  int t = a;
  a = b;
  b = t;
}

int partition(float *arr, const int left, const int right)
{
  const int mid = left + (right - left) / 2;
  const int pivot = arr[mid];
  // move the mid point value to the front.
  swap(arr[mid], arr[left]);
  int i = left + 1;
  int j = right;
  while (i <= j)
  {
    while (i <= j && arr[i] <= pivot)
    {
      i++;
    }

    while (i <= j && arr[j] > pivot)
    {
      j--;
    }

    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i - 1], arr[left]);
  return i - 1;
}

void quickSort(float *arr, const int left, const int right)
{
  if (left >= right)
  {
    return;
  }

  int part = partition(arr, left, right);

  quickSort(arr, left, part - 1);
  quickSort(arr, part + 1, right);
}

int median(float arr[], int maxValues)
{
  quickSort(arr, 0, maxValues - 1);
  return arr[maxValues / 2];
}

void SensorModule::config(CMMC_System *os, AsyncWebServer* server) { 
  static SensorModule *that = this;
}
void SensorModule::configLoop() { 
} 

void SensorModule::setup() { 
  
}

void SensorModule::loop() { 
  interval.every_ms(1000, [&]() {
    int idx = counter++ % MAX_ARRAY;
    // temp_array[idx] = dht->readTemperature();
    // humid_array[idx] = dht->readHumidity();

    if (counter < MAX_ARRAY)
        {
          // _temperature = median(temp_array, idx + 1);
          // _humidity = median(humid_array, idx + 1);
        }
        else
        {
          // _temperature = median(temp_array, MAX_ARRAY);
          // _humidity = median(humid_array, MAX_ARRAY);
        }    
  });
}

float SensorModule::getTemperature() {
  return _temperature;
}


float SensorModule::getHumidity() {
  return _humidity;
}