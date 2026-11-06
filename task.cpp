
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node* firstChild;
    Node* nextSibling;
};

Node* createNode(string value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;

    return newNode;
}

void relationShipBuilder(Node* parent, Node* child)
{
    if (parent->firstChild == NULL)
    {
        parent->firstChild = child;
    }
    else
    {
        Node* q = parent->firstChild;

        while (q->nextSibling != NULL)
        {
            q = q->nextSibling;
        }

        q->nextSibling = child;
    }
}

void DisplayOrganogram(Node* root, int level = 0)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < level; i++)
    {
        cout << "\t";
    }

    cout << root->data << endl;

    Node* q = root->firstChild;

    while (q != NULL)
    {
        DisplayOrganogram(q, level + 1);
        q = q->nextSibling;
    }
}

int main()
{
    Node* chancellor = createNode("Chancellor");
    Node* rector = createNode("Rector");

    Node* proRector1 = createNode("Pro Rector Academics");
    Node* proRector2 = createNode("Pro Rector Administration");
    Node* proRector3 = createNode("Pro Rector Research");

    Node* registrar = createNode("Registrar");
    Node* directorQEC = createNode("Director QEC");

    Node* deanEngineering = createNode("Dean Faculty of Engineering");
    Node* deanManagement = createNode("Dean Faculty of Management Sciences");
    Node* deanComputer = createNode("Dean Faculty of Computer Sciences");

    Node* hodSoftware = createNode("HOD Software Engineering");
    Node* hodComputer = createNode("HOD Computer Science");
    Node* hodManagement = createNode("HOD Management Sciences");

    Node* faculty1 = createNode("Assistant Professor");
    Node* faculty2 = createNode("Lecturer");

    Node* directorHR = createNode("Director HR");
    Node* directorFinance = createNode("Director Finance");
    Node* directorAdmissions = createNode("Director Admissions");

    Node* directorORIC = createNode("Director ORIC");

    relationShipBuilder(chancellor, rector);

    relationShipBuilder(rector, proRector1);
    relationShipBuilder(rector, proRector2);
    relationShipBuilder(rector, proRector3);
    relationShipBuilder(rector, registrar);
    relationShipBuilder(rector, directorQEC);

    relationShipBuilder(proRector1, deanEngineering);
    relationShipBuilder(proRector1, deanManagement);
    relationShipBuilder(proRector1, deanComputer);

    relationShipBuilder(deanEngineering, hodSoftware);
    relationShipBuilder(deanComputer, hodComputer);
    relationShipBuilder(deanManagement, hodManagement);

    relationShipBuilder(hodSoftware, faculty1);
    relationShipBuilder(hodSoftware, faculty2);

    relationShipBuilder(proRector2, directorHR);
    relationShipBuilder(proRector2, directorFinance);
    relationShipBuilder(proRector2, directorAdmissions);

    relationShipBuilder(proRector3, directorORIC);

    cout << "Chart is given below: " << endl;

    DisplayOrganogram(chancellor);

    return 0;
}