#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum
{
    AVAILABLE,
    BORROWED,
    OVERDUE
} BookStatus;

typedef enum
{
    BORROW,
    RETURN,
    NOTHING
} TransactionType;

typedef struct
{
    int bookID;
    char title[100];
    BookStatus status;
    char borrowerName[50];
    int daysBorrowed;
} Book;

typedef struct
{
    int transID;
    int bookID;
    char borrowerName[50];
    TransactionType type;
} Transaction;

typedef struct node
{
    Book book;
    struct node *next;
} BookList, *BlPtr, *NodePtr, Node;

typedef struct node
{
    Transaction transaction;
    struct node *next;
} TransactionRecord;

Book createBook(int bookID, char *title, BookStatus status)
{
    Book newB;
    newB.bookID = bookID;
    strcpy(newB.title, title);
    newB.status = status;
    strcpy(newB.borrowerName, "");
    newB.daysBorrowed = 0;
    return newB;
}
Transaction createTransaction(int id, int bID, char *name, TransactionType type)
{
    Transaction t;
    t.transID = id;
    t.bookID = bID;
    strcpy(t.borrowerName, name);
    t.type = type;
    return t;
}

bool bookInList(BlPtr *bl, Book b)
{
    NodePtr *trav = bl;
    while (trav)
    {
        if ((*trav)->book.bookID == b.bookID && (*trav)->book.status == AVAILABLE)
        {
            break;
        }
        trav = &(*trav)->next;
    }
    return true;
}

bool addToBook(BlPtr *bl, Book b)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (!newNode)
    {
        return false;
    }
    newNode->book = b;
    newNode->next = NULL;

    NodePtr *trav = bl;
    if (trav && !bookInList(bl, b))
    {
        while (trav)
        {
            trav = &(*trav)->next;
        }
        *trav = newNode;
        (*trav)->book.status = AVAILABLE;
        return true;
    }
    return false;
}

Transaction borrowBook(BlPtr *bl, char *borrower, int daysBorrowing, Book b)
{
    Transaction t = createTransaction(0, 0, "", NOTHING);
    NodePtr *trav = bl;
    if (!trav)
    {
        printf("List is empty, nothing to borrow");
        return t;
    }
    while (trav && (*trav)->book.bookID != b.bookID)
    {
        trav = &(*trav)->next;
    }
    if ((*trav)->book.status == AVAILABLE)
    {
        t.bookID = (*trav)->book.bookID;
        strcpy(t.borrowerName, borrower);
        (*trav)->book.status = BORROWED;
        (*trav)->book.daysBorrowed = daysBorrowing;
        t.type = BORROW;
    }
    return t;
}
Transaction returnBook(BlPtr *bl, int bookID)
{
    Transaction t = createTransaction(0, 0, "", NOTHING);
    NodePtr *trav = bl;

    if (!trav)
    {
        printf("List is empty\n");
        return t;
    }
    while (trav && (*trav)->book.bookID != bookID)
    {
        trav = &(*trav)->next;
    }
    if ((*trav)->book.status == BORROWED)
    {
        t.bookID = (*trav)->book.bookID;
        strcpy(t.borrowerName, "");
        (*trav)->book.status = BORROWED;
        t.type = ((*trav)->book.daysBorrowed > 30) ? OVERDUE : AVAILABLE;
        (*trav)->book.daysBorrowed = 0;
    }
    return t;
}

#endif