/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int x[10]; 
int bin[1024][10]; 

void Try(int k, int numsSize, int* idx) 
{
    if (k == numsSize) 
    {
        for (int i = 0; i < numsSize; i++) 
        {
            bin[*idx][i] = x[i];
        }
        (*idx)++;
        return; 
    }

    for (int i = 0; i <= 1; i++) 
    {
        x[k] = i;
        Try(k + 1, numsSize, idx);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    int idx = 0;
    int total = 1 << numsSize; // 2^numsSize
    *returnSize = total;

    // Sinh tat ca cac xau nhi phan vao mang bin
    Try(0, numsSize, &idx);

    int** sub = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));

    for (int i = 0; i < total; i++) 
    {
        sub[i] = (int*)malloc(numsSize * sizeof(int));
        
        int count = 0;
        for (int j = 0; j < numsSize; j++) 
        {
            if (bin[i][j] == 1) 
            {
                sub[i][count++] = nums[j];
            }
        }
        
        (*returnColumnSizes)[i] = count;
    }

    return sub;
}