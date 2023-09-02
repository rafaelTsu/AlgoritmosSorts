import time
import random

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)

    merged = merge(left_half, right_half)

    return merged

def merge(left, right):
    result = []
    left_idx, right_idx = 0, 0

    while left_idx < len(left) and right_idx < len(right):
        if left[left_idx] < right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1

    result.extend(left[left_idx:])
    result.extend(right[right_idx:])

    return result

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[random.randint(0, len(arr) - 1)]
    left = []
    right = []
    equal = []

    for element in arr:
        if element < pivot:
            left.append(element)
        elif element == pivot:
            equal.append(element)
        else:
            right.append(element)

    return quick_sort(left) + equal + quick_sort(right)

def counting_sort(arr):
    max_val = max(arr)
    min_val = min(arr)
    range_of_elements = max_val - min_val + 1
    count_arr = [0] * range_of_elements
    output_arr = [0] * len(arr)

    for i in range(len(arr)):
        count_arr[arr[i] - min_val] += 1

    for i in range(1, len(count_arr)):
        count_arr[i] += count_arr[i - 1]

    for i in range(len(arr) - 1, -1, -1):
        output_arr[count_arr[arr[i] - min_val] - 1] = arr[i]
        count_arr[arr[i] - min_val] -= 1

    return output_arr

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        
def heapify(arr, n, i):
    largest = i
    left_child = 2 * i + 1
    right_child = 2 * i + 2

    if left_child < n and arr[left_child] > arr[largest]:
        largest = left_child

    if right_child < n and arr[right_child] > arr[largest]:
        largest = right_child

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    # Build a max heap.
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements from the max heap one by one.
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Swap the maximum element with the last element.
        heapify(arr, i, 0)


# Function to generate a list of 'x' random integers between a specified range
def generate_random_list(x, min_value, max_value):
    return [random.randint(min_value, max_value) for _ in range(x)]

# Function to measure sorting time and return the sorted list
def measure_time(input_list,sorting_function):
    start_time = time.time()  # Record the start time
    sorted_list = sorting_function(input_list)
    end_time = time.time()  # Record the end time

    elapsed_time = end_time - start_time
    return  elapsed_time


if __name__ == "__main__":
    print("Heapsort")
    for x in range(1000, 21000, 1000):
        lista = generate_random_list(x,1,20000)
        tempo = measure_time(lista,heap_sort)
        print(x,tempo, "seconds")
        
    print()   
    print("Quicksort")
    for x in range(1000, 21000, 1000):
        lista = generate_random_list(x, 1, 20000)
        tempo = measure_time(lista, quick_sort)
        print(x, tempo, "seconds")
        
    print()
    print("Mergesort")
    for x in range(1000, 21000, 1000):
        lista = generate_random_list(x, 1, 20000)
        tempo = measure_time(lista, merge_sort)
        print(x, tempo, "seconds")

    print()
    print("Selectionsort")
    for x in range(1000, 21000, 1000):
        lista = generate_random_list(x, 1, 20000)
        tempo = measure_time(lista, selection_sort)
        print(x, tempo, "seconds")
        
    print()
    print("Countingsort")
    for x in range(1000, 21000, 1000):
        lista = generate_random_list(x, 1, 20000)
        tempo = measure_time(lista, counting_sort)
        print(x, tempo, "seconds")
    
    print()
    print("Insertionsort")
    for x in range(1000, 21000, 1000):
        lista = generate_random_list(x, 1, 20000)
        tempo = measure_time(lista, insertion_sort)
        print(x, tempo, "seconds")
