/*
 * ANE_Test_003.c
 *
 *  Created on: Sep 7, 2012
 *      Author: jeff
 */


#include "stdlib.h"
#include "ANE_OSX.h"
#include "strings.h"


FREObject isSupported(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
{
  FREObject result = 0;

  uint32_t isSupportedInThisOS = 1;
  FRENewObjectFromBool( isSupportedInThisOS, result);

  return result;
}

FREObject getTestString(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
{
  FREObject result;

  const char *str = "This is a string from ANE!";
  FRENewObjectFromUTF8(strlen(str)+1, (const uint8_t *)str, &result);

  return result;
}

FREObject getHelloWorld(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
{
  FREObject result;

  const char *str = "Hello World!! This is your DLL talking!";
  FRENewObjectFromUTF8(strlen(str)+1, (const uint8_t *)str, &result);

  return result;
}


void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions)
{
  *numFunctions = 3;
  FRENamedFunction* func = (FRENamedFunction*) malloc(sizeof(FRENamedFunction) * (*numFunctions));

  func[0].name = (const uint8_t*) "getTestString";
  func[0].functionData = NULL;
  func[0].function = &getTestString;

  func[1].name = (const uint8_t*) "isSupported";
  func[1].functionData = NULL;
  func[1].function = &isSupported;

  func[2].name = (const uint8_t*) "getHelloWorld";
  func[2].functionData = NULL;
  func[2].function = &getHelloWorld;

  *functions = func;
}

void contextFinalizer(FREContext ctx)
{
  return;
}

void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer)
{
  *ctxInitializer = &contextInitializer;
  *ctxFinalizer = &contextFinalizer;
}

void finalizer(void* extData)
{
  return;
}





