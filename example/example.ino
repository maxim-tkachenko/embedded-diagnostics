#include "Diagnostics.h"
#include "testClass.h"

class testClass2 {
public:
  testClass2() {
    traceme;
  }
  ~testClass2() {
    traceme;
  }
  void testFunc2() {
    traceme;
  }
};

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  traceme;

  testClass tc;
  tc.testFunc();

  testClass2 tc2;
  tc2.testFunc2();

  Serial.println("test");
}

void loop() {
  // put your main code here, to run repeatedly:
  traceme;
  delay(1000);
}