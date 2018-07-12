#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int a[], int pleft[], int left_count, int pright[], int right_count)
{
   int i=0, j=0, n=0;
   while(i<left_count || j<right_count)
   {
      if(i==left_count)
      {
         a[n++] = pright[j++];
      }
      else if(j==right_count)
      {
         a[n++] = pleft[i++];
      }
      else if(pleft[i] < pright[j])
      {
         a[n++] = pleft[i++];
      }
      else
         a[n++] = pright[j++];
   }
}

void divide_sort(int a[], int n)
{
   int left_count, right_count;
   int *pleft, *pright;
   if(n<=1)
      return;
   left_count = n/2;
   right_count = n-n/2;
   pleft = (int *)malloc(sizeof(a[0])*left_count);
   pright = (int *)malloc(sizeof(a[0])*right_count);
   memcpy(pleft, &a[0], sizeof(a[0])*left_count);
   memcpy(pright, &a[left_count], sizeof(a[0])*right_count);
   divide_sort(pleft, left_count);
   divide_sort(pright, right_count);
   merge(a, pleft, left_count, pright, right_count);
   free(pleft);
   free(pright);
}

main()
{
   int a[]={11, 55, 44, 33, 22};
   /*
   left: 11, 55
      left:11, right:55
      合并:11,55
   right: 44, 33, 22
      left:44, right:33, 22
                   left:33, right:22
                   合并:22, 33
      合并:22, 33, 44
   合并:11,22,33,44,55
   */
   int n = sizeof(a)/sizeof(a[0]);
   int i;
   divide_sort(a, n);
   for(i=0; i<n; i++)
      printf("%d ", a[i]);
}


