#include "BookManager.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

//Struktura
Book::Book(int bookID, const string& bookTitle, const string& bookAuthor, bool availability)
{
}

Book Book::fromString(const string& line)
{
	return Book();
}

string Book::toString() const
{
	return string();
}

//Klasa

BookManager::BookManager(const string& file)
{
	loadFromFile();
}

BookManager::~BookManager()
{
	saveToFile();
}

void BookManager::removeBook(int id)
{
}

void BookManager::searchBook(const string& keyword) const
{
}

void BookManager::displayBooks() const
{
}

void BookManager::updateAvailability(int id, bool availability)
{
}
