#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
    int ht;
};

struct node* root=NULL;

struct node* create(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory cannot be allocated\n");
        return NULL;
    }

        newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
};

struct node* rotateleft(struct node* root)
{
    struct node* rightchild=root->right;
    root->right=rightchild->left;
    rightchild->left=root;

    root->ht=height(root);
    rightchild->ht=height(rightchild);

    return rightchild;
};

struct node* rotateright(struct node* root)
{
    struct node* leftchild=root->left;
    root->left=leftchild->right;
    leftchild->right=root;

    root->ht=height(root);
    leftchild->ht=height(leftchild);

    return leftchild;
};

int balancefactor(struct node* root)
{
    int lh, rh;
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL)
    {
        return 0;
    }
    else
    {
        lh=1+root->left->ht;
    }
    if(root->right==NULL)
    {
        rh=0;
    }
    else
    {
        rh=1+root->right->ht;
    }

    return lh - rh;
}

int height(struct node* root)
{
    int lh,rh;
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL)
    {
        lh=0;
    }
    else
    {
        lh=1+root->left->ht;
    }
    if(root->right==NULL)
    {
        rh=0;
    }
    else
    {
        rh=1+root->right->ht;
    }

    if(lh>rh)
        return(lh);
    return(rh);
}

struct node* insert(struct node* root, int data)
{
    if (root == NULL)
    {
        struct node* newnode = create(data);
        if (newnode == NULL)
        {
            return NULL;
        }
        root = newnode;
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);

        if (balancefactor(root) == -2)
        {
            if (data > root->right->data)
            {
                root = rotateleft(root);
            }
            else
            {
                root->right = rotateright(root->right);
                root = rotateleft(root);
            }
        }
    }
    else
    {
        root->left = insert(root->left, data);

        if (balancefactor(root) == 2)
        {
            if (data < root->left->data)
            {
                root = rotateright(root);
            }
            else
            {
                root->left = rotateleft(root->left);
                root = rotateright(root);
            }
        }
    }
    root->ht = height(root);
    return root;
}

struct node * delete(struct node *root, int x)
{
    struct node * temp = NULL;

    if (root == NULL)
    {
        return NULL;
    }

    if (x > root->data)
    {
        root->right = delete(root->right, x);
        if (balancefactor(root) == 2)
        {
            if (balancefactor(root->left) >= 0)
            {
                root = rotateright(root);
            }
            else
            {
                root->left = rotateleft(root->left);
                root = rotateright(root);
            }
        }
    }
    else if (x < root->data)
    {
        root->left = delete(root->left, x);
        if (balancefactor(root) == -2)
        {
            if (balancefactor(root->right) <= 0)
            {
                root = rotateleft(root);
            }
            else
            {
                root->right = rotateright(root->right);
                root = rotateleft(root);
            }
        }
    }
    else
    {
        if (root->right != NULL)
        {
            temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            root->data = temp->data;
            root->right = delete(root->right, temp->data);
            if (balancefactor(root) == 2)
            {
                if (balancefactor(root->left) >= 0)
                {
                    root = rotateright(root);
                }
                else
                {
                    root->left = rotateleft(root->left);
                    root = rotateright(root);
                }
            }
        }
        else
        {
            return (root->left);
        }
    }
    root->ht = height(root);
    return (root);
}

struct node* search(struct node* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if(root->data == key)
    {
        return root;
    }

    if(key > root->data)
    {
        search(root->right, key);
    }
    else
    {
        search(root->left, key);
    }
}

void print_level(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d\t", root->data);
    else if (level > 1)
    {
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}
void levelorder(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    int ht = height(root);

    for (int level = 1; level <= ht; level++)
    {
        int count = printTree(root, level);
        printf("Level %d: %d nodes\n", level, count);
    }
}

int printTree(struct node *root, int level)
{
    if (root == NULL)
        return 0;
    if (level == 1)
    {
        printf("%d\t", root->data);
        return 1;
    }
    else if (level > 1)
    {
        int left_count = printTree(root->left, level - 1);
        int right_count = printTree(root->right, level - 1);
        return left_count + right_count;
    }
    return 0;
}

void inorder(struct node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
     printf("%d   ",root->data);
    inorder(root->right);
}

void preorder(struct node* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d   ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
      printf("%d   ",root->data);
}

int main()
{
    int userchoice, data;
    int level;
    struct node* result = NULL;
    int l,u,N;
    FILE *fp;
    printf("\n enter range lower and upper:");
    scanf("%d%d",&l,&u);
    printf("\n enter count:");
    scanf("%d",&N);
    fp=fopen("input.txt","w");
    if(fp==NULL)
    {
        printf("\nerror");
        exit(0);
    }
    int i,array[1000];
     srand(time(0));
     printf("\n the random numbers are:  ");
     for(i=0;i<N;i++)
    {
        array[i]=(rand() % (u-l+1))+l;
        printf("\n%d",array[i]);
        fprintf(fp,"%d\t",array[i]);
        root=insert(root,array[i]);
    }

    fclose(fp);
    while (1)
    {
        printf("\n\n------- AVL TREE --------\n");
        printf("\n1. Delete");
        printf("\n2. Search");
        printf("\n3. Inorder");
        printf("\n4. Preorder");
        printf("\n5. Postorder");
        printf("\n6. EXIT");
        printf("\n7. print");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &userchoice);

        switch(userchoice)
        {

            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = delete(root,data);
                break;

            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                result = search(root,data);
                if (result == NULL)
                {
                    printf("\nNode not found!");
                }
                else
                {
                    printf("\n Node found");
                }
                break;
            case 3:
                inorder(root);
                break;

            case 4:
                preorder(root);
                break;

            case 5:
                postorder(root);
                break;

            case 6:
                printf("\n\tProgram Terminated\n");
                return 1;

            case 7:
                printf("tree structure:\n");
                levelorder(root);
                break;

            default:
                printf("\n\tInvalid Choice\n");
        }
    }

    return 0;
}


