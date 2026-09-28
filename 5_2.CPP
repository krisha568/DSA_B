#include <iostream>
#include <string>
using namespace std;

struct SNode {
    string name;
    SNode *next;
};

struct DNode {
    string name;
    DNode *prev, *next;
};

SNode *sh = NULL;
DNode *dh = NULL;

void addS(string s) {
    SNode *n = new SNode{s, NULL};
    if (!sh) {
        sh = n;
        n->next = sh;
        return;
    }
    SNode *t = sh;
    while (t->next != sh) t = t->next;
    t->next = n;
    n->next = sh;
}

void delS(string s) {
    if (!sh) return;
    SNode *t = sh, *p = NULL;
    do {
        if (t->name == s) break;
        p = t;
        t = t->next;
    } while (t != sh);

    if (t->name != s) return;

    if (t == sh) {
        if (sh->next == sh) sh = NULL;
        else {
            SNode *last = sh;
            while (last->next != sh) last = last->next;
            sh = sh->next;
            last->next = sh;
        }
    } else p->next = t->next;
    delete t;
}

void showS() {
    if (!sh) {
        cout << "Empty\n";
        return;
    }
    SNode *t = sh;
    do {
        cout << t->name << " ";
        t = t->next;
    } while (t != sh);
    cout << endl;
}

void addD(string s) {
    DNode *n = new DNode{s, NULL, NULL};
    if (!dh) {
        dh = n;
        n->next = n;
        n->prev = n;
        return;
    }
    DNode *last = dh->prev;
    n->next = dh;
    n->prev = last;
    last->next = n;
    dh->prev = n;
}

void delD(string s) {
    if (!dh) return;
    DNode *t = dh;
    do {
        if (t->name == s) break;
        t = t->next;
    } while (t != dh);

    if (t->name != s) return;

    if (t->next == t) dh = NULL;
    else {
        t->prev->next = t->next;
        t->next->prev = t->prev;
        if (t == dh) dh = t->next;
    }
    delete t;
}

void showD() {
    if (!dh) {
        cout << "Empty\n";
        return;
    }
    DNode *t = dh;
    do {
        cout << t->name << " ";
        t = t->next;
    } while (t != dh);
    cout << endl;
}

int main() {
    cout << "Singly Circular:\n";
    addS("A"); showS();
    addS("B"); showS();
    addS("C"); showS();
    delS("B"); showS();

    cout << "Doubly Circular:\n";
    addD("A"); showD();
    addD("B"); showD();
    addD("C"); showD();
    delD("B"); showD();

    return 0;
}