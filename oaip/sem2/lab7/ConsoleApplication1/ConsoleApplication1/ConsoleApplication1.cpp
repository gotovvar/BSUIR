#include <iostream>
#include <string>

using namespace std;

struct node 
{
    int info;  
    string name; 
    node* left; 
    node* right; 
    int balance; 
};

int Height(node* root) 
{
    if (root == NULL) return 0; 
    int hLeft = Height(root->left), 
        hRight = Height(root->right); 
    if (hLeft > hRight) 
        return hLeft + 1; 
    else  
        return hRight + 1; 
}

void SetBalance(node* (&root)) 
{
    if (root != NULL)  
        root->balance = Height(root->right) - Height(root->left); 
}

void TurnRight(node* (&root)) 
{
    node* leftSubtree, * leftSubtreeRightSubtree; // rightSubtree - указатель на левое поддерево; rightSubtreeLeftSubtree - указатель на правое поддерево для левого поддерва 
    leftSubtree = root->left; //присваиваем значение левого поддерева 
    leftSubtreeRightSubtree = leftSubtree->right; // присваиваем значение правого поддерева для левого поддерева 

    leftSubtree->right = root; // присваиваем Х как правое поддерево А
    root->left = leftSubtreeRightSubtree; // Т2 присваивается Х
    root = leftSubtree; // присваиваем А, как новую вершину 
    SetBalance(root->right);
    SetBalance(root);
}

void TurnLeft(node* (&root)) 
{
    node* rightSubtree, * rightSubtreeLeftSubtree;
    rightSubtree = root->right;
    rightSubtreeLeftSubtree = rightSubtree->left;

    rightSubtree->left = root;
    root->right = rightSubtreeLeftSubtree;
    root = rightSubtree;
    SetBalance(root->left);
    SetBalance(root);
}

void Insert(node* (&root), int d, string name) 
{
    if (root == NULL) 
    {  
        root = new node; 
        root->info = d; 
        root->name = name;
        root->balance = 0;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if (d > root->info)
        {
            Insert(root->right, d, name);
            if (Height(root->right) - Height(root->left) > 1) 
            {
                if (Height(root->right->right) < Height(root->right->left))
                    TurnRight(root->right); 
                TurnLeft(root); 
            }
        }
        else
            if (d < root->info)
            {
                Insert(root->left, d, name);  
                if (Height(root->left) - Height(root->right) > 1) 
                {
                    if (Height(root->left->left) < Height(root->left->right)) 
                     
                        TurnLeft(root->left); 
                    TurnRight(root);  
                }
            }
            else
                cout << "Данный элемент уже присутствует в дереве" << endl;
        SetBalance(root);// пересчитываем значение баланса 
    }
}

void PrintInorder(node* root) 
{
    if (root == NULL)
        return;
    PrintInorder(root->left); 
    cout << root->info << " | " << root->name << endl; 
    PrintInorder(root->right); 
}

void PrintPreorder(node* root)
{
    if (root == NULL)
        return;
    cout << root->info << " | " << root->name << endl;
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}

void Delete(int x, node* (&root))
{
    node* d;
    if (root == NULL)
    {
        cout << "Sorry, but there isn't such element\n" << endl;
    }
    else if (x < root->info) 
    {
        Delete(x, root->left);
    }
    else if (x > root->info)  
    {
        Delete(x, root->right);
    }
    else if ((root->left == NULL) && (root->right == NULL))  
    {
        d = root;
        free(d); // Функция free() возвращает память, на которую указывает параметр назад в кучу.В резуль­тате эта память может выделяться снова.
        root = NULL;
        cout << "Element removed\n" << endl;
    }
    else if (root->left == NULL) 
    {
        d = root;
        root = root->right;
        free(d);
        cout << "Element removed\n" << endl;
    }
    else if (root->right == NULL) 
    {
        d = root;
        root = root->left;
        free(d);
        cout << "Element removed\n" << endl;
    }
    else 
    {
        root->right->left = root->left;
        root = root->right;
        d = root->right;
        free(d);
        cout << "Element removed\n" << endl;
    }
    return SetBalance(root);
}

void Clear(node* (&p)) 
{
    if (p != NULL)
    {
        Clear(p->left);
        Clear(p->right);

        delete p;
        p = NULL;
    }
}

node* Search(node* root, int value)
{
    if (root->info < value)
        return Search(root->right, value);
    else if (root->info > value)
        return Search(root->left, value);
    else
        return root;

}

void Task(node* root, int &count) {
    if (root == NULL)
        return;
    count++;
    Task(root->left,count); 
    Task(root->right,count); 

}

void View_Tree(node* p, int level) {
    string str;
    if (p) {
        View_Tree(p->right, level + 1);		
        for (int i = 0; i < level; i++) {
            str = str + "    ";
        }
        str += to_string(p->info);  
        cout << str << endl;
        View_Tree(p->left, level + 1); 			
    }
}

int main()
{
    node* root = NULL;
    int operation, value, size;
    string name;
    while (true) {
        cout << "1) - Create tree\n"
            << "2) - Add\n"
            << "3) - Delete\n"
            << "4) - Inorder traversal\n"
            << "5) - Preorder traversaln\n"
            << "6) - View tree\n"
            << "7) - Find\n"
            << "8) - Individual task\n"
            << "0) - Exit\n\n";
        cin >> operation;
        switch (operation) {
        case 1:
            cout << "Enter the size of tree\n";
            cin >> size;
            cout << "Enter tree\n\n";
            for (int i = 0; i < size; ++i) {
                cout << "Enter value of new node\n";
                cin >> value;
                cout << "Enter name of new node\n";
                cin >> name;
                Insert(root, value, name);
            }
            break;
        case 2:
            cout << "Enter value of new node\n";
            cin >> value;
            cout << "Enter name of new node\n";
            cin >> name;
            Insert(root, value, name);
            break;
        case 3:
            cout << "Enter value of node\n";
            cin >> value;
            Delete(value, root);
            break;
        case 4:
            PrintInorder(root);
            cout << endl;
            break;
        case 5:
            PrintPreorder(root);
            cout << endl;
            break;
        case 6:
            View_Tree(root, 0);
            break;
        case 7:
            cout << "Enter value of node\n";
            cin >> value;
            if (!Search(root, value))
                cout << "Sorry, but there isn't such element\n";
            cout << Search(root, value)->name << endl;
            break;
        case 8: {
            int count = 0;
            Task(root->left, count);
            cout <<  count << endl;
            break;
        }
        case 0:
            Clear(root);
            return 0;
        }
    }
}
