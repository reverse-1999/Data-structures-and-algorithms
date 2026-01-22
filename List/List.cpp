#include <stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
	//struct Node* prior;
}Node;


Node* List_create(int length)
{
	if (length <= 0) return NULL;
	Node* head = (Node*)malloc(sizeof(Node));//创建头节点
	if (head == NULL) return NULL;
	head->next = NULL;
	head->data = 0;
	Node* cursor = head;//创建临时游标指针
	for (int i = 0; i < length; i++)
	{
		Node* new_node = (Node*)malloc(sizeof(Node));
		if (new_node == NULL) { return NULL; }//可优化为释放多余节点再返回，也可添加错误提示
		new_node->next = NULL;
		new_node->data = i + 1;
		cursor->next = new_node;
		cursor = cursor->next;
	}
	return head;
}

void Free(Node* head)//if (head){ Node* cursor = head->next; free(head); Free(cursor);}
{
	if (head)
	{
		Node* cursor1 = head->next;
		Node* cursor2 = head->next;
		free(head);
		while (cursor1 != NULL)
		{
			cursor2 = cursor1->next;
			free(cursor1);
			cursor1 = cursor2;
		}
	}
}

void List_Print(Node* head)
{
	if (head == NULL) { printf("error\n");  return; }
	Node* cursor = head;
	printf("head--->");
	while (cursor->next != NULL)
	{
		printf("%d--->", cursor->next->data);
		cursor = cursor->next;
	}
	printf("NULL\n");
}

int main()
{
	int len = 10;
	Node* first = List_create(len);

	List_Print(first);
	Free(first);

}















