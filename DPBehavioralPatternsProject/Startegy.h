#pragma once
#include <iostream>

using namespace std;

class I—ompression 
{
public:
	virtual void compress(string file) = 0;
	virtual ~I—ompression() {}
};
	
class Archiver
{
	I—ompression* compression;
public:
	Archiver(I—ompression* compression)
		: compression{ compression } {};
	I—ompression*& Compression() { return compression; }

	void Archiving(string file)
	{
		compression->compress(file);
	}
};

class Rar—ompression : public I—ompression
{
public:
	void compress(string file) override
	{
		cout << "file " << file << "compress with RAR algorithm\n";
	}
};

class Arj—ompression : public I—ompression
{
public:
	void compress(string file) override
	{
		cout << "file " << file << "compress with ARJ algorithm\n";
	}
};

class Zip—ompression : public I—ompression
{
public:
	void compress(string file) override
	{
		cout << "file " << file << "compress with ZIP algorithm\n";
	}
};

