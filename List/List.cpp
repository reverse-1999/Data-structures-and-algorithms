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

void List_add_in_end(Node* head)//不支持空链表
{
	if (head == NULL) { printf("error\n");  return; }
	Node* cursor = head;
	while (cursor->next != NULL)
	{
		cursor = cursor->next;
	}
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) { printf("error\n");  return; }
	new_node->next = NULL;
	new_node->data = cursor->data+1;
	cursor->next = new_node;
	return;
}

void List_add_in_all(Node* head, int pos)//pos适用于0-length
{
	if (head == NULL) { printf("error\n");  return; }	
	Node* new_node = (Node*)malloc(sizeof(Node));	
	if (new_node == NULL) { printf("error\n");  return; }
	Node* cursor = head;
	int i = 0;
	if(pos <0) { printf("error\n");  return; }
	else if (pos == 0)
	{
		new_node->next = cursor->next;
		cursor->next = new_node;
		new_node->data = 1;

	}
	else {
		while (i < pos && cursor != NULL)
		{
			cursor = cursor->next;
			i++;
		}
		if(i!=pos) { printf("error\n");  return; }
		new_node->next = cursor->next;
		new_node->data = cursor->data + 1;
		cursor->next = new_node;
	}
		cursor = new_node->next;
		while (cursor != NULL)
		{
			cursor->data += 1;
			cursor = cursor->next;
		}
}

void List_delete(Node* head,int idx)//index:1-length
{
	if (head == NULL) { printf("error\n");  return; }
	if(idx<=0) { printf("error\n");  return; }
	Node* cursor = head;
	int i = 0;

	while (idx-1 > i && cursor->next != NULL)//定位到idx前一个节点
	{
		cursor = cursor->next;  
		i++;
	}
	if(i != idx-1) { printf("error\n");  return; }
	Node* temp_cursor = cursor->next;
	if(cursor->next == NULL) { printf("error\n");  return; }
	cursor->next = cursor->next->next;
	free(temp_cursor);
}

int List_find(Node* head,int data)
{
	if (head == NULL) { printf("error\n");  return -1; }
	int idx = 1;
	Node* cursor = head->next;
	while (cursor != NULL && data != cursor->data)
	{
		idx++;
		cursor = cursor->next;
	}
	if(cursor == NULL) { printf("error\n");  return -1; }
	return idx;
}

void List_Reverse(Node* head)//反转链表,带无数据头节点
{
	if (head == NULL || head->next == NULL) { printf("error\n");  return; }
	Node* cursor1 = head->next->next;
	Node* cursor2 = head->next;
	Node* cursor3 = head->next;
	
	while (cursor1 != NULL)
	{	
		cursor2 = cursor1;
		cursor1 = cursor1->next;
		
		cursor2->next = cursor3;
		cursor3 = cursor2;
	}
	head->next->next = NULL;
	head->next = cursor2;
	return;
}

void List_Reverse_2(Node* head)//反转链表,无哨兵头节点
{
	if (head == NULL) { printf("error\n");  return; }
	Node* cursor1 = head->next;
	Node* cursor2 = head;
	Node* cursor3 = head;

	while (cursor1 != NULL)
	{
		cursor2 = cursor1;
		cursor1 = cursor1->next;

		cursor2->next = cursor3;
		cursor3 = cursor2;
	}
	head->next = NULL;
	return;
}

int main()
{
	int len = 10;
	Node* first = List_create(len);
	//for (int j = 0; j < 5; j++)
	//{
	//	List_add_in_end(first);
	//}
	List_add_in_all(first, 10);
	List_delete(first, 5);
	List_Print(first);
	List_Reverse(first);
	List_Print(first);
	Free(first);

}















