#include <stdio.h>
void check(int array1[], int s1, int array2[], int s2, int bit[]) {
    for (int i=0;i<s1;i++) {
        int found = 0;
        for (int j=0;j<s2;j++) {
            if (array1[i] == array2[j]) {
                found = 1;
                break;
            }
        }
        bit[i] = found;
    }
}
void unio(int array1[], int s1, int array2[], int s2, int uni[]) {
    for (int i=0;i<s1;i++) {
        uni[i] = (array1[i] || array2[i]);
  }}
void intersection(int array1[], int s1, int array2[], int s2, int intersect[]) {
    for (int i=0;i<s1;i++) {
        intersect[i] = (array1[i] && array2[i]);
 }}
void difference(int array1[], int s1, int array2[], int s2, int diff[]) {
    for (int i=0;i<s1;i++) {
        diff[i] = (array1[i] && ~array2[i]);
  }}
int main() {
    int s1,s2,s3;
    printf("Enter the size of universal set:\n");
    scanf("%d",&s1);
    int array1[s1];
    printf("Enter the universal set:\n");
    for(int i=0;i<s1;i++)
    {
        scanf("%d",&array1[i]);
    }

    printf("Enter the size of 1st subset:\n");
    scanf("%d",&s2);
    int array2[s2];
    printf("Enter first subset:");
    for(int i=0;i<s2;i++)
    {
        scanf("%d",&array2[i]);
    }
     printf("Enter the size ofm 2nd subset:\n");
    scanf("%d",&s3);
    int array3[s3];
    printf("Enter second subset:");
    for(int i=0;i<s3;i++)
    {
        scanf("%d",&array3[i]);
    }

    int bit1[s1];
    int bit2[s1];
    int uni[s1];
    int intersect[s1];
    int diff[s1];

    check(array1,s1,array2,s2,bit1);
    check(array1,s1,array3,s3,bit2);
    unio(bit1,s1,bit2,s1,uni);
    intersection(bit1,s1,bit2, s1,intersect);
    difference(bit1,s1,bit2,s2,diff);
  
  printf("\nUniversal set:\n ");
    for (int i = 0; i < s1; i++) {
        printf("%d ",array1[i]);
    }
      printf("\n1st subset: \n");
    for (int i = 0; i < s2; i++) {
        printf("%d ", array2[i]);
    }
     printf("\n{");
    for (int i = 0; i < s1; i++) {
        printf("%d ", bit1[i]);
    }
    printf("}");
      printf("\n2nd subset:\n ");
    for (int i = 0; i < s3; i++) {
        printf("%d ", array3[i]);
    }

    printf("\n{");
    for (int i = 0; i < s1; i++) {
        printf("%d ", bit2
               [i]);
    }
      printf("}");
     printf("\nUnion Bitstring:\n ");
    for (int i = 0; i < s1; i++) {
        printf("%d ", uni[i]);
    }
          printf("\nUnion:\n ");
    for (int i = 0; i < s1; i++) {
       if(uni[i]==1)
        printf("%d ", array1[i]);
    }

     printf("\nIntersection  bitstring:\n ");
    for (int i = 0; i < s1; i++) {
        printf("%d ", intersect[i]);
    }
  printf("\n Intersection:\n");
 for(int i=0;i<s1;i++)
  {
if(intersect[i]==1)

   printf("%d",array1[i]);

  }

 printf("\nDifference:\n ");
    for (int i = 0; i < s1; i++) {
       if(diff[i]==1)
        printf("%d ", array1[i]);
    }
printf("\n Difference Bitstring:\n");
 for(int i=0;i<s1;i++){
if(diff[i]==1)
printf("%d ",diff[i]);
}
    return 0;
}





