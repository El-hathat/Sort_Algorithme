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


int t[8];
    double tbulle[8]; 
    double tinsertion[8] ;
    double trapide[8];
    double tselection[8];
    double ttas[8];
    double tbase[8];
    double tcount[8];

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
    int i = low;

    for ( j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

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
   
    int max = 0;
    for ( i = 0; i < n; i++) {
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
    int max = 0;
    for ( i = 0; i < n; i++) {
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
    int ki=0;
    for ( ki = 0; ki < n; ki++) {
        arr[ki] = rand() % 1000;  // Valeurs aléatoires entre 0 et 999
       
    }
    
}


void remptableau(int arr[], int n) {
    int ki=0;
    for ( ki = 0; ki < n; ki++) {
        arr[ki] = ki;  // Valeurs aléatoires entre 0 et 999
    }
    printf(" tableau 2 est plein ");
}
//####################################################################################################################
//####################################TRI############################################################################
 void tri(int arr[],char fichier[30],int d,int n){
    
   // printf("Entrez la taille du tableau : ");
    //scanf("%d", &n);

    

    // Initialisation du générateur de nombres aléatoires
    

     // Remplir le tableau aléatoirement

    clock_t start, end;
    double temp_Utiliser;
    
    
    // Mesurer le temps de tri à bulles
    
    
  //  while(d<6){
       // n=n*(d+1);
       // int *newArr = (int *)realloc(arr, n * sizeof(int));
       // arr = newArr;
       // fillRandom(arr, n);
         t[d]=n;
         
//############## bubble Sort ########################
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
       
        tbulle[d]=temp_Utiliser;
        printf("\n tri  1");
//############## insertionSort #######################
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
        tinsertion[d]=temp_Utiliser;
        printf("\n tri  2");
//############## tri rapide #######################
        start = clock();
        quickSort(arr, 0,n-1);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
        trapide[d]=temp_Utiliser;
        printf("\n tri  3");
//############## tri par sélection #######################
        start = clock();
        selectionSort(arr,n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
        tselection[d]=temp_Utiliser;
        printf("\n tri  4");
//############## tri par tas #######################
        start = clock();
        heapSort(arr,n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
        ttas[d]=temp_Utiliser;
        printf("\n tri  5");
//############## tri de base #######################
        start = clock();
        radixSort(arr,n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
       tbase[d]=temp_Utiliser;
        printf("\n tri  6");
//############## tri par comptage #######################
        start = clock();
        countingSort(arr,n);
        end = clock();
        temp_Utiliser = ((double)(end - start)) / CLOCKS_PER_SEC;
       tcount[d]=temp_Utiliser;
        printf("\n tri  7");
//####################################################################################
       
       printf("\n %d %f %f %f %f %f %f %f \n",t[d],tbulle[d],tinsertion[d],trapide[d],tselection[d],ttas[d],tbase[d],tcount[d]);
        //printf(" \n tableau est trier contient %d \n ",n);
        
   // }
printf("\n tri pour le %d fois ",d);
    // Stocker les résultats dans donnees.txt
    FILE *results = fopen(fichier, "a");
  
    fprintf(results, "%d %f %f %f %f %f %f %f \n",t[d],tbulle[d],tinsertion[d],trapide[d],tselection[d],ttas[d],tbase[d],tcount[d]);
    

    fclose(results);

   
    
   
 }


void viderFichier(){
    FILE *result1 = fopen("../donnees.txt", "w");
    FILE *result2 = fopen("../donnees1.txt", "w");
    fprintf(result1, "");
    fprintf(result2, "");
    fclose(result1);
    fclose(result2);
}


int main() {
int step=0;
     int n=500;
    srand(time(NULL));
   viderFichier();
   int *arr = (int *)malloc(n * sizeof(int));
for ( step= 0; step < 7; step++)
{
    printf("\n1er tri");
      n=n*(step+1);
      int *newArr = (int *)realloc(arr, n *(step+1)* sizeof(int));
       arr = newArr;
       fillRandom(arr, n);
    //  printf("\n val du tab1 %d\n",n);
       tri(arr,"../donnees.txt",step,n);
       printf("\nFin de 1er");


printf("\n2eme tri \n");
       remptableau(arr, n);
       tri(arr,"../donnees1.txt",step,n);
       printf("\nFin de 2eme");
       
}



    
     free(arr);   
   printf("Fin de Programme");
   
    return 0;
}
