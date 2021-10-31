# include <iostream>
# include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;

    Node()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }
};

Node* createBTree(Node* root,Node* newnode)
{
    if(root == NULL)
    {
        return newnode;
    }
    else if(newnode->val < root->val)
    {
        root->left =  createBTree(root->left,newnode);
    }
    else if(newnode->val > root->val)
    {
        root->right =  createBTree(root->right,newnode);
    }
    else //if(newnode->val == root->val)
    {
        cout << "Node already there" << endl;
        return root;
    }
    return root;
}

int max(int a,int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

void inOrder(Node* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

void preOrder(Node* root)
{
    if(root != NULL)
    {
        cout << root->val << " ";
        inOrder(root->left);
        inOrder(root->right);
    }
}

void postOrder(Node* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        inOrder(root->right);
        cout << root->val << " ";
    }
}

void levelOrder(Node* root)
{
    Node* temp;
    queue<Node*> q;
    q.push(root);
    while(q.empty() == false)
    {
        temp = q.front();
        cout << temp->val << " ";
        q.pop();

        if(temp->left != NULL)
        {
            q.push(temp->left);
        }

        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

int maxWidth(Node* root)
{
    Node* temp;
    queue<Node*> q;
    q.push(root);
    int max_width = 0;
    while (q.empty() == false)
    {
        temp = q.front();
        max_width = max(max_width,q.size());
        q.pop();

        if(temp->left != NULL)
        {
            q.push(temp->left);
        }

        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
    }

    return max_width;
}

int heightOfTree(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    return 1 + max(lh,rh);
}

int diameterOfTree(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    int ldia = diameterOfTree(root->left);
    int rdia = diameterOfTree(root->right);

    return max(1+lh+rh , max(ldia,rdia));
}

void printNodeAtK(Node* root,int k)
{
    if(root == NULL)
    {
        return;
    }

    if(k == 0)
    {
        cout << root->val << " ";
    }

    k = k-1;
    printNodeAtK(root->left,k);
    printNodeAtK(root->right,k);
}

int distanceFromRoot(Node* root,int x)
{
    if(root == NULL)
    {
        return 0;
    }

    if(x < root->val)
    {
        return 1 + distanceFromRoot(root->left,x);
    }
    else if(x > root->val)
    {
        return 1 + distanceFromRoot(root->right,x);
    }

    return 0;
}

int distanceBetween2Nodes(Node* root,int a,int b)
{
    if(root == NULL)
    {
        return 0;
    }

    if(a > b)
    {
        swap(a,b);
    }

    if(a < root->val && b < root->val)
    {
        return distanceBetween2Nodes(root->left,a,b);
    }
    else if(a > root->val && b > root->val)
    {
        return distanceBetween2Nodes(root->right,a,b);
    }
    else if(a <= root->val && b >= root->val)
    {
        return distanceFromRoot(root,a) + distanceFromRoot(root,b);
    }
    
    return 0;
}

bool findPath(Node* root,vector<int> &path,int x)
{
    if(root == NULL)
    {
        return false;
    }

    path.push_back(root->val);

    if(root->val == x)
    {
        return true;
    }

    if((root->left != NULL && findPath(root->left,path,x) == true) || 
        (root->right != NULL && findPath(root->right,path,x) == true))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int findLCA(Node* root,int a,int b)
{
    vector<int> path1;
    vector<int> path2;

    if(findPath(root,path1,a) == false || findPath(root,path2,b) == false)
    {
        return -1;
    }

    int i;
    for(i=0;i<path1.size();i++)
    {
        if(path1[i] != path2[i])
        {
            break;
        }
    }

    return path1[i-1];
}

int main()
{
    /*
    sample tree used
                7
        5               10
    3       6       9       12
    */

    int arr[] = {7,5,10,3,6,9,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    Node* root = NULL;
    for(int i=0;i<n;i++)
    {
        Node* newnode = new Node();
        newnode->val = arr[i];
        root = createBTree(root,newnode);
    }

    inOrder(root);
    cout << endl;

    preOrder(root);
    cout << endl;

    postOrder(root);
    cout << endl;

    levelOrder(root);
    cout << endl;

    cout << "maxWidth(root) => " << maxWidth(root) << endl;

    cout << "heightOfTree => " << heightOfTree(root) << endl;
    cout << "diameterOfTree => " << diameterOfTree(root) << endl;

    cout << "printNodeAtK => ";
    printNodeAtK(root,1);
    cout << endl;

    // Note : distance == count links
    cout << "distanceFromRoot(root,6) => " << distanceFromRoot(root,6) << endl;
    cout << "distanceBetween2Nodes(root,6,12) => " << distanceBetween2Nodes(root,6,12) << endl;

    vector<int> path;
    cout << "findPath(root,path,6) => " << findPath(root,path,6) << endl;
    cout << "path : ";
    for(int i=0;i<path.size();i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;

    cout << "findLCA(3,6) => " << findLCA(root,3,6) << endl;
    cout << isCProperty(root) << endl;

    return 0;
}