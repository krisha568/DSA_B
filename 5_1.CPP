#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node *prev, *next;
};

Node *head = NULL;

void addBeginning(string s)
{
    Node *n = new Node{s, NULL, head};

    if (head != NULL)
        head->prev = n;

    head = n;
}

void addEnd(string s)
{
    Node *n = new Node{s, NULL, NULL};

    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

void insertAfter(string oldSong, string newSong)
{
    Node *temp = head;

    while (temp != NULL && temp->song != oldSong)
        temp = temp->next;

    if (temp == NULL)
        return;

    Node *n = new Node{newSong, temp, temp->next};

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;
}

void removeFirst()
{
    if (head == NULL)
        return;

    Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

int countSongs()
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void display()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->song << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    addBeginning("Song2");
    display();

    addEnd("Song3");
    display();

    addBeginning("Song1");
    display();

    insertAfter("Song2", "NewSong");
    display();

    cout << "Total songs: " << countSongs() << endl;

    removeFirst();
    display();

    cout << "Total songs: " << countSongs() << endl;

    return 0;
}