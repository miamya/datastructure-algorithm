#include <iostream>
#include <queue>

struct Node
{
    int data;
    Node* parent = NULL;
    Node* firstchild = NULL;
    Node* nextsibling = NULL;
    Node* prevsibling = NULL;
};

Node* root = NULL;
Node* current = NULL;



void addNode(int data)
{
    if (root == NULL) //add root
    {
        Node* node = new Node();//create new node
        node->data = data;//masukin data kedalem node baru
        root = node;
        current = root;
    }
    else if (current->firstchild == NULL) //add firstchild
    {
        Node* temp = new Node();
        temp->data = data;
        current->firstchild = temp;
        temp->parent = current;
        current = temp;
    }
    else //add sibling
    {
        Node* temp = current->firstchild;
        while (temp->nextsibling != NULL)
        {
            temp = temp->nextsibling;
        }
        Node* temp2 = new Node();
        temp2->data = data;
        temp->nextsibling = temp2;
        temp2->prevsibling = temp;
        temp2->parent = current;
        current = temp2;
    }
}

void moveToFirstChild()
{
	if (current){
    if (current->firstchild)
    {
        current = current->firstchild;
        std::cout << "Moved to first child.\n";
    }
    else
    {
        std::cout << "Not available.\n";
    }
}
}

void moveToParent()
{
	if(current){
	if (current->parent)
    {
        current = current->parent;
        std::cout << "Moved to parent.\n";
    }
    else
    {
        std::cout << "Not available.\n";
    }
	}
}

void moveToNextSibling()
{
	if(current){
	if (current->nextsibling)
    {
        current = current->nextsibling;
        std::cout << "Moved to next sibling.\n";
    }
    else
    {
        std::cout << "Not available.\n";
    }
}
}

void moveToPrevSibling()
{
	if (current){
    if (current->prevsibling)
    {
        current = current->prevsibling;
        std::cout << "Moved to next sibling.\n";
    }
    else
    {
        std::cout << "Not available.\n";
    }
}
}
    
void printCurrent()
{
    if (current)
    {
        std::cout << "Current: " << current->data << std::endl;
    }
    else
    {
        std::cout << "Not available\n";
    }
}

void printSiblings()
{ 
    if(current != root){
    if (current->nextsibling || current->prevsibling)
    {
        Node* temp = current->parent;
        temp = temp->firstchild;
        std::cout << "Siblings: ";
        while (temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->nextsibling;
        }
    }
        std::cout << '\n';
    }
}

void removeNode()
{

    // if current is root
    if (current == root)
    {
        // if root doesn't have child
        if (!current->firstchild)
        {
            free(current);
            current = NULL;
            root = NULL;
        }
        // if root has child
        else if (current->firstchild)
        {
            // if the child of root doesnt have child
            if (!current->firstchild->firstchild)
            {
                Node* temp = current->firstchild;
                if (temp->nextsibling)
                {
                    Node* temp2 = temp;
                    while (temp2->nextsibling)
                    {
                        temp2 = temp2->nextsibling;
                        if (temp2->prevsibling == temp)
                        {
                            temp2->parent = temp;
                            temp->firstchild = temp2;
                            temp->nextsibling = NULL;
                            temp2->prevsibling = NULL;
                        }
                        else
                        {
                            temp2->parent = temp;
                        }
                    }
                }
                temp->parent = NULL;
                free(current);
                root = temp;
                current = root;
            }
            // if the child of root has child
            else if (current->firstchild->firstchild)
            {
                Node* temp = current->firstchild;
                Node* temp2 = temp->firstchild;
                if (temp2->nextsibling && temp->nextsibling)
                {
                    while (temp2->nextsibling)
                    {
                        temp2 = temp2->nextsibling;
                    }
                    temp2->nextsibling = temp->nextsibling;
                    temp2->nextsibling->prevsibling = temp2;
                }
                else if(!temp2->nextsibling)
                {
                    if (temp->nextsibling)
                    {
                        temp2->nextsibling = temp->nextsibling;
                        temp2->nextsibling->prevsibling = temp2;
                    }
                }
                temp->parent = NULL;
                free(current);
                root = temp;
                current = root;
            }
        }
    }
    // if current doesn't have child
    else if (current->firstchild == NULL)
    {
        Node* temp = current;
        current = current->parent;

        // if current is first child, make next sibling the first child
        if (!temp->prevsibling)
        {
            if (temp->nextsibling)
            {
                current->firstchild = temp->nextsibling;
            }
            else
            {
                current->firstchild = NULL;
            }
        }
        // if current is in the middle
        else if (temp->prevsibling && temp->nextsibling)
        {
            temp->prevsibling->nextsibling = temp->nextsibling;
            temp->nextsibling->prevsibling = temp->prevsibling;
        }
        // if current is the last child
        else if(!temp->nextsibling)
        {
            temp->prevsibling->nextsibling = NULL;
        }
        free(temp);
    }
    // if current has child or children
    else if (current->firstchild)
    {
        Node* temp;
        Node* temp2;
        Node* temp3;
        // if current is the first child
        if (!current->prevsibling)
        {
            // if the child of current has child or children
            if (current->firstchild->firstchild)
            {
                temp = current->firstchild;
                temp2 = temp->firstchild;
                if (temp->nextsibling)
                {
                    while (temp2->nextsibling)
                    {
                        temp2 = temp2->nextsibling;
                    }
                    temp2->nextsibling = temp->nextsibling;
                    temp->nextsibling->prevsibling = temp2;
                }
                
                temp3 = current->firstchild;
                if (temp3->nextsibling)
                {
                    while (temp3->nextsibling)
                    {
                        temp3 = temp3->nextsibling;
                        temp3->parent = temp;
                    }
                    temp->nextsibling = NULL;
                }
               
                temp->parent = current->parent;
                temp->parent->firstchild = temp;

                if (current->nextsibling)
                {
                    temp->nextsibling = current->nextsibling;
                    temp->nextsibling->prevsibling = temp;
                }
                free(current);
                current = temp;
            }
            // if the child of current doesnt have child
            else if (!current->firstchild->firstchild)
            {
                temp = current->firstchild;
                temp2 = temp;
                if (temp2->nextsibling)
                {
                    while (temp2->nextsibling)
                    {
                        temp2 = temp2->nextsibling;
                        if (temp2->prevsibling == temp)
                        {
                            temp2->prevsibling = NULL;
                            temp->nextsibling = NULL;
                            temp2->parent = temp;
                            temp->firstchild = temp2;
                        }
                        else
                        {
                            temp2->parent = temp;
                        }
                    }
                }
                temp->parent = current->parent;
                temp->parent->firstchild = temp;
                if (current->nextsibling)
                {
                    temp->nextsibling = current->nextsibling;
                    temp->nextsibling->prevsibling = temp;
                }
                free(current);
                current = temp;
            }
        }
        // if current is the middle child
        else if (current->prevsibling && current->nextsibling)
        {
            // if current's firstchild has firstchild
            if (current->firstchild->firstchild)
            {
                temp = current->firstchild;
                temp2 = temp->firstchild;
                if (temp->nextsibling)
                {
                    while (temp2->nextsibling)
                    {
                        temp2 = temp2->nextsibling;
                    }
                    temp2->nextsibling = temp->nextsibling;
                    temp->nextsibling->prevsibling = temp2;
                }

                temp3 = current->firstchild;
                if (temp3->nextsibling)
                {
                    while (temp3->nextsibling)
                    {
                        temp3 = temp3->nextsibling;
                        temp3->parent = temp;
                    }
                }

                temp->parent = current->parent;
                temp->nextsibling = current->nextsibling;
                temp->nextsibling->prevsibling = temp;
                temp->prevsibling = current->prevsibling;
                temp->prevsibling->nextsibling = temp;
                free(current);
                current = temp;
            }
            // If current firstchild doesn't have child
            else if (!current->firstchild->firstchild)
            {
                temp = current->firstchild;
                temp2 = temp;
                if (temp2->nextsibling)
                {
                    while (temp2->nextsibling)
                    {
                        temp2 = temp2->nextsibling;
                        if (temp2->prevsibling == temp)
                        {
                            temp2->prevsibling = NULL;
                            temp->nextsibling = NULL;
                            temp2->parent = temp;
                            temp->firstchild = temp2;
                        }
                        else
                        {
                            temp2->parent = temp;
                        }
                    }
                }
                temp->parent = current->parent;

                temp->nextsibling = current->nextsibling;
                temp->nextsibling->prevsibling = temp;
                temp->prevsibling = current->prevsibling;
                temp->prevsibling->nextsibling = temp;
        
                free(current);
                current = temp;
            }
        }
        // if current is the last child
        else if (!current->nextsibling)
        {
            // if current firstchild has child
            if (current->firstchild->firstchild)
            {
                temp = current->firstchild;
                temp2 = temp->firstchild;
                if (temp->nextsibling)
                {
                    while (temp2->nextsibling)
                    {
                        temp2 = temp2->nextsibling;
                    }
                    temp2->nextsibling = temp->nextsibling;
                    temp->nextsibling->prevsibling = temp2;
                }

                temp3 = current->firstchild;
                if (temp3->nextsibling)
                {
                    while (temp3->nextsibling)
                    {
                        temp3 = temp3->nextsibling;
                        temp3->parent = temp;
                    }
                    temp->nextsibling = NULL;
                }

                temp->parent = current->parent;
                temp->prevsibling = current->prevsibling;
                temp->prevsibling->nextsibling = temp;
                free(current);
                current = temp;
            }
            // if current firstchild doesnt have child
            else if (!current->firstchild->firstchild)
            {
                temp = current->firstchild;
                temp2 = temp;
                if (temp2->nextsibling)
                {
                    while (temp2->nextsibling)
                    {
                        temp2 = temp2->nextsibling;
                        if (temp2->prevsibling == temp)
                        {
                            temp2->prevsibling = NULL;
                            temp->nextsibling = NULL;
                            temp2->parent = temp;
                            temp->firstchild = temp2;
                        }
                        else
                        {
                            temp2->parent = temp;
                        }
                    }
                }
                temp->parent = current->parent;
                temp->prevsibling = current->prevsibling;
                temp->prevsibling->nextsibling = temp;

                free(current);
                current = temp;
            }
        }
    }
}

void printAll()
{   
    if (root)
    {
        Node* temp;
        Node* temp2;
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            for (int i = q.size(); i > 0; --i)
            {
                temp = q.front();
                q.pop();
                std::cout << temp->data << ' ';
                if (temp->firstchild != NULL)
                {
                    if (temp->firstchild->nextsibling)
                    {
                        temp2 = temp->firstchild;
                        while (temp2)
                        {
                            q.push(temp2);
                            temp2 = temp2->nextsibling;
                        }
                    }
                    else
                    {
                        q.push(temp->firstchild);
                    }
                }
            }
            std::cout << '\n';
        }
    }
    else
    {
        std::cout << "Not available.\n";
    }
    
}

void removeSubtree()
{
    while (current->firstchild)
    {
        removeNode();
    }
    removeNode();
}

void initialize()
{
    current = root;
    removeSubtree();
}

int main()
{
    int menu;
    bool repeat = true;

    Node* node = new Node();
    node->data = 1;
    root = node;
    current = root;

    Node* node2 = new Node();
    node2->data = 2;
    node->firstchild = node2;
    node2->parent = node;

    Node* node3 = new Node();
    node3->data = 3;
    node3->parent = node;
    node2->nextsibling = node3;
    node3->prevsibling = node2;

    Node* node4 = new Node();
    node4->data = 4;
    node4->parent = node;
    node3->nextsibling = node4;
    node4->prevsibling = node3;

    Node* node5 = new Node();
    node5->data = 5;
    node2->firstchild = node5;
    node5->parent = node2;

    Node* node6 = new Node();
    node6->data = 6;
    node6->parent = node2;
    node5->nextsibling = node6;
    node6->prevsibling = node5;

    Node* node7 = new Node();
    node7->data = 7;
    node7->parent = node6;
    node6->firstchild = node7;

    Node* node8 = new Node();
    node8->data = 8;
    node8->parent = node6;
    node8->prevsibling = node7;
    node7->nextsibling = node8;

    Node* node9 = new Node();
    node9->data = 9;
    node9->parent = node8;
    node8->firstchild = node9;

    Node* node10 = new Node();
    node10->data = 10;
    node10->parent = node3;
    node3->firstchild = node10;

    Node* node11 = new Node();
    node11->data = 11;
    node11->parent = node10;
    node10->firstchild = node11;

    Node* node12 = new Node();
    node12->data = 12;
    node12->parent = node11;
    node11->firstchild = node12;

    Node* node13 = new Node();
    node13->data = 13;
    node13->parent = node11;
    node13->prevsibling = node12;
    node12->nextsibling = node13;

    Node* node14 = new Node();
    node14->data = 14;
    node14->parent = node4;
    node4->firstchild = node14;

    Node* node15 = new Node();
    node15->data = 15;
    node15->parent = node4;
    node15->prevsibling = node14;
    node14->nextsibling = node15;

    Node* node16 = new Node();
    node16->data = 16;
    node16->parent = node4;
    node->prevsibling = node15;
    node15->nextsibling = node16;

    Node* node17 = new Node();
    node17->data = 17;
    node17->parent = node15;
    node15->firstchild = node17;

    Node* node18 = new Node();
    node18->data = 18;
    node18->parent = node15;
    node->prevsibling = node17;
    node17->nextsibling = node18;

    Node* node19 = new Node();
    node19->data = 19;
    node19->parent = node18;
    node18->firstchild = node19;

    Node* node20 = new Node();
    node20->data = 20;
    node20->parent = node16;
    node16->firstchild = node20;



    while (repeat) {
        std::cout << "Choose your program:" << std::endl;
        std::cout << "1. Initialize" << std::endl;
        std::cout << "2. Add Node" << std::endl;
        std::cout << "3. Move to First Child" << std::endl;
        std::cout << "4. Move to Next Sibling" << std::endl;
        std::cout << "5. Move to Previous Sibling" << std::endl;
        std::cout << "6. Move to Parent" << std::endl;
        std::cout << "7. Print Current" << std::endl;
        std::cout << "8. Print Siblings" << std::endl;
        std::cout << "9. Print All" << std::endl;
        std::cout << "10. Remove Node" << std::endl;
        std::cout << "11. Remove Subtree" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "______________________________________________" << std::endl;
        std::cin >> menu;
        std::cout << std::endl;
        switch (menu)
        {
            case 1: // Initialize
            {
                initialize();
                break;
            }

            case 2: // Add node
            {
                int userInput;
                std::cout << "Input a number: ";
                std::cin >> userInput;
                addNode(userInput);
                break;
            }

            case 3: 
            {
                moveToNextSibling();
                break;
            }

            case 4: 
            {
                moveToPrevSibling();
                break;
            }

            case 5: 
            {
                moveToFirstChild();
                break;
            }

            case 6: // Move to parent
            {
                moveToParent();
                break;
            }

            case 7: // Print current
            {
                printCurrent();
                break;
            }

            case 8: // Print siblings
            {
                printSiblings();
                break;
            }

            case 9: // Print all
            {
                 printAll();
                 break;
            }

            case 10: // Remove node 
            {
                removeNode();
                break;
            }

            case 11: // Remove subtree
            {
                 removeSubtree();
                 break;
            }

            case 0: // exit
            {
                return 0;
            }
        }
    }
}
