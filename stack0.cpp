

int n;
static int i = 0,j = n-1;
void stack1_push(int x)
{
    if(i + 1 == j)  { printf("error\n");  return; }
    arr[i] = x;
    i++;
}
void stack1_pop()
{
    if(i == 0) { printf("error\n");  return; }
    i--;
}
void stack2_push(int x)
{
    if(j +1 == i) { printf("error\n");  return; }
    arr[j] = x;
    j--;
}
void stack2_pop()
{
    if(j == n-1) { printf("error\n");  return; }
    j++;
}


