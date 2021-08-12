# embedded-diagnostics

Simple tracing capabilities: just copy the file to your project and include in every file where you want to use tracing, then put `traceme` wherever you want to write to serial the func/ctor/etc. name along with signature. When your sketch is ready for production, just comment out `TRACE_ENABLED` flag to disable tracing. When it's disabled, it does cost nothing for your flash and RAM!

So the next code:
```C++
#include "Diagnostics.h"

class testClass
{
public:
  testClass()
  {
    traceme;
  }
  ~testClass()
  {
    traceme;
  }
  void testFunc()
  {
    traceme;
  }
};

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  traceme;

  testClass t;
  t.testFunc();

  Serial.println("test");
  foo();
  bar(1);
}

void loop()
{
  // put your main code here, to run repeatedly:
  traceme;
  delay(1000);
}

void foo()
{
  traceme;
}

byte bar(byte b)
{
  traceme;
  return b;
}
```
will produce next output to Serial port:
```
TRACE: void setup()
TRACE: testClass::testClass()
TRACE: void testClass::testFunc()
test
TRACE: void foo()
TRACE: byte bar(byte)
TRACE: testClass::~testClass()
TRACE: void loop()
TRACE: void loop()
...
```
