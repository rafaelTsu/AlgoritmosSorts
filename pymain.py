import math
import time
import random

#Merge Sort
def merge(lista, ini, meio, fim):
    left = lista[ini:meio]
    right = lista[meio:fim]
    i, j = 0, 0

    for k in range(ini, fim):
        if i >= len(left):
            lista[k] = right[j]
            j += 1
        elif j >= len(right):
            lista[k] = left[i]
            i += 1
        elif left[i] < right[j]:
            lista[k] = left[i]
            i += 1
        else:
            lista[k] = right[j]
            j += 1

def mergesort(lista, ini=0, fim=None):
    if fim is None:
        fim = len(lista)
    if(fim - ini > 1):
        meio = (fim + ini)//2
        mergesort(lista, ini, meio)
        mergesort(lista, meio, fim)
        merge(lista, ini, meio, fim)

#Insertion Sort
def insertion(lista):
    n = len(lista)
    for j in range(2, n):
        key = lista[j]
        i = j - 1
        while(i >= 0 and lista[i] > key):
            lista[i+1] = lista[i]
            i = i - 1
        lista[i+1] = key

#Selection Sort
def selection(lista):
    n = len(lista)
    for j in range(n-1):
        min_index = j
        for i in range(j, n):
            if(lista[i]<lista[min_index]):
                min_index = i
        if(lista[j] > lista[min_index]):
            aux = lista[j]
            lista[j] = lista[min_index]
            lista[min_index] = aux

#Heap Sort



#Quick Sort
def partition(lista, ini, fim):
    pivot = lista[fim]
    i = ini
    for j in range(ini, fim):
        if (lista[j] <= pivot):
            aux = lista[j]
            lista[j] = lista[i]
            lista[i] = aux
            i += 1
    aux = lista[i]
    lista[i] = lista[fim]
    lista[fim] = aux
    return i

def quick(lista, ini=0, fim=None):
    if fim is None:
        fim = len(lista)-1

    if(ini<fim):
        p = partition(lista, ini, fim)
        quick(lista, ini, p-1)
        quick(lista, p+1, fim)

#Calcula média
def calcula_media(lista, ini):
    n = len(lista)
    media = 0
    for i in range(ini, n):
        media += lista[i]
    return media/(n-ini)

media_selection = []
media_insertion = []
media_merge = []
media_heap = []
media_quick = []
media_counting = []

print("Digite o tamanho inicial do vetor: ")
inc = int(input())

print("Digite o fim do vetor: ")
fim = int(input())

print("Digite o intervalo entre dois vetores: ")
stp = int(input())

print("Digite quantas vezes o vetor deve ser repetido: ")
rpt = int(input())

print("[[RANDOM]]")
print("   n    Selection       Insertion       Merge       Quick       Heap       Counting")
print("-----------------------------------------------------------------------------------")
aleatorio = inc

aux = 0
while(aleatorio <= fim):
    print("%d" %aleatorio, end="    ")
    cont = 0
    while(cont < rpt):
        any_numbers = random.sample(range(0,30000), aleatorio)
        lista_selection = any_numbers[:]
        lista_insertion = any_numbers[:]
        lista_merge = any_numbers[:]
        lista_quick = any_numbers[:]

        start_time = time.time()
        selection(lista_selection)
        end_time = time.time()

        media_selection.append(end_time - start_time)

        start_time = time.time()
        insertion(lista_insertion)
        end_time = time.time()

        media_insertion.append(end_time - start_time)

        start_time = time.time()
        mergesort(lista_merge)
        end_time = time.time()

        media_merge.append(end_time - start_time)

        start_time = time.time()
        quick(lista_quick)
        end_time = time.time()

        media_quick.append(end_time - start_time)

        cont += 1

    print("%.6f" %calcula_media(media_selection, aux), end="        ")
    print("%.6f" %calcula_media(media_insertion, aux), end="        ")
    print("%.6f" %calcula_media(media_merge, aux), end="        ")
    print("%.6f" %calcula_media(media_quick, aux))


    aux += cont
    aleatorio += stp


'''
any_numbers = random.sample(range(1,1000), 20)
lista = any_numbers
quick(lista)
print(lista)
'''