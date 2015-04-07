#include "Point2f.h"
#include "String.h"
#include "SList.h"
#include "DList.h"
#include "DynArray.h"
#include "globals.h"

#include "Projectile.h"
#include "Point2f.h"

int main(int argc, char** argv)
{
	String a("1234567890");
	String b("asdfasdfasdfasdfasdfasdfsdaf");
	b = "hola";
	a.prefix(b);
	b.prefix("1234567890");


	return 0;
}