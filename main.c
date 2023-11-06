#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//##############################################################################################################################################
/*
Ce projet creer par Mohamed El-hathat, Sami El-Qassri et Ouissal.
Propriétés de l'ordinateur :
                            -Lenovo ThinkPad T460
                            -i5 6éme generation
                            -8 Go RAM
                            -256 Go SSD Stokage
*/
//###############################################################################################################################################

int i,j;
//####################################################################################################
// Fonction de tri à bulles
void bubbleSort(int arr[], int n) {
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
   // printf(" tableau est trier ");
}
//#############################################################################################
// Fonction de tri à insertion
void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
//######################################################################################################
// Fonction pour échanger deux éléments d'un tableau
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction pour choisir un pivot (dans cet exemple, le dernier élément)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for ( j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fonction principale de tri rapide
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//#####################################################################################################################
// Fonction de tri par sélection
void selectionSort(int arr[], int n) {
    int i, j, min_index;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Échanger l'élément actuel avec l'élément le plus petit trouvé
        swap(&arr[i], &arr[min_index]);
    }
}
//###########################################################################################################

// Fonstruction d'un tas max (max-heap)
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Fonction de tri par tas
void heapSort(int arr[], int n) {
    // Construction du tas max (max-heap)
    for ( i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extraction d'éléments du tas et tri
    for ( i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Échange l'élément racine (le plus grand) avec le dernier élément non trié
        maxHeapify(arr, i, 0);  // Appel maxHeapify pour le tas réduit
    }
}
//############################################################################################################################

// Fonction pour trouver le chiffre maximal d'un tableau
int findMax(int arr[], int n) {
    int max = arr[0];
    for ( i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Fonction de tri de base (Radix Sort)
void radixSort(int arr[], int n) {
    int max = findMax(arr, n); // Trouver le chiffre maximal
int exp;
    for ( exp = 1; max / exp > 0; exp *= 10) {
        int output[n];
        int count[10] = {0};

        // Compter le nombre d'occurrences de chaque chiffre
        for ( i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        // Mettre à jour les comptages cumulatifs
        for ( i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Construire le tableau de sortie
        for ( i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // Copier le tableau de sortie dans le tableau d'origine
        for ( i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}
//#####################################################################################################################
// Fonction de tri par comptage
void countingSort(int arr[], int n) {
    int max = arr[0];
    for ( i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Créer un tableau de comptage
    int* count = (int*)malloc((max + 1) * sizeof(int));

    for ( i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Compter les occurrences de chaque élément
    for ( i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Réorganiser les éléments dans le tableau trié
    int k = 0;
    for ( i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[k] = i;
            k++;
            count[i]--;
        }
    }

    free(count);
}

//####################################################################################################################
// Fonction pour remplir le tableau aléatoirement
void fillRandom(int arr[], int n) {
    for ( i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Valeurs aléatoires entre 0 et 999
    }
    //printf(" tableau est plein ");
}
//####################################################################################################################

int main() {
    int n=500;
   // printf("Entrez la taille du tableau : ");
    //scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

     // Remplir le tableau aléatoirement

    clock_t start, end;
    double temp_Utiliser;
    
    
    // Mesurer le temps de tri à bulles
    int *t = (int )malloc(5 * sizeof(int));
    double *tbulle = (int )malloc(5 * sizeof(double));
    double *tinsertion = (int )malloc(5 * sizeof(double));
    double *trapide = (int )malloc(5 * sizeof(double));
    double *tselection = (int )malloc(5 * sizeof(double));
    double *ttas = (int )malloc(5 * sizeof(double));
    double *tbase = (int )malloc(5 * sizeof(double));
    double *tcount = (int )malloc(5 * sizeof(double));
    int d=0;
    while(d<5){
        n=n*(d+1);
        int *newArr = (int *)realloc(arr, n * sizeof(int));
        arr = newArr;
        fillRandom(arr, n);
         t[d]=n;
//############## bubble Sort ########################
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
       
        tbulle[d]=temp_Utiliser;
//############## insertionSort #######################
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
        tinsertion[d]=temp_Utiliser;
//############## tri rapide #######################
        start = clock();
        quickSort(arr, 0,n-1);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
        trapide[d]=temp_Utiliser;
//############## tri par sélection #######################
        start = clock();
        selectionSort(arr,n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
        tselection[d]=temp_Utiliser;
//############## tri par tas #######################
        start = clock();
        heapSort(arr,n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
        ttas[d]=temp_Utiliser;
//############## tri de base #######################
        start = clock();
        radixSort(arr,n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
        tbase[d]=temp_Utiliser;
//############## tri par comptage #######################
        start = clock();
        countingSort(arr,n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
        tcount[d]=temp_Utiliser;

//####################################################################################
        d++;
       // printf(" data enregistrer ");
        //printf(" \n tableau est trier contient %d \n ",n);
        
    }

    // Stocker les résultats dans donnees.txt
    FILE *results = fopen("../donnees.txt", "w");
    for(i=0;i<6;i++){
    fprintf(results, "%d %f %f %f %f %f %f %f \n",t[i],tbulle[i],tinsertion[i],trapide[i],tselection[i],ttas[i],tbase[i],tcount[i]);
    }

    fclose(results);

   
    printf("Fin de Programme");
    free(arr);
    return 0;
}
