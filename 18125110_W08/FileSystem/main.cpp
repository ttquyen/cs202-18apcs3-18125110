#include"file.h"
#include"folder.h"
#include"item.h"


void main()
{
	CFolder C("C");
	CFolder System("System");
	CFolder Windows("Windows");
	CFile a_txt("a.txt", 123);
	CFile b_doc("b.doc", 456);
	System.add(&a_txt);
	Windows.add(&b_doc);
	C.add(&System);
	C.add(&Windows);
	cout << "Content of folder C ->" << endl;
	C.print(0); // print hidden items or not? 1/0
	CItem* p = C.removeByName("System");
	cout << "Content of folder C afer removing folder System ->" << endl;
	C.print(0);
	p = C.findByName("b.doc");
	if (p != NULL)
	{
		cout << "b.doc is found in folder C" << endl;
	}
	else
	{
		cout << "b.doc is not found" << endl;
	}
	p = C.findByName("a.txt");
	if (p != NULL)
	{
		cout << "a.txt is found" << endl;
	}
	else
	{
		cout << "a.txt is not found" << endl;
	}
	p = C.findByName("Windows");
	if (p != NULL)
	{
		cout << "Folder Windows is folder. Content of folder Windows ->" <<

			endl;

		p->setHidden(true, true); // set HIDDEN to folder p and all its items
		p->print(0);
		p->setHidden(true, true); // set HIDDEN to folder p and do not change
									//hidden attributes of its sub - items
	}
	else
	{
		cout << "Folder Windows is not found" << endl;
	}
	system("pause");
}

