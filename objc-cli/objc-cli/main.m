//
//  main.m
//  objc-cli
//
//  Created by ewu on 23/2/20.
//  Copyright © 2020 ewu. All rights reserved.
//
// https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/Introduction/Introduction.html#//apple_ref/doc/uid/TP40011210-CH1-SW1
#import <Foundation/Foundation.h>
#import "SimpleClass.h"

int main(int argc, const char * argv[]) {
    SimpleClass *simpleClass = [[SimpleClass alloc] init];
    [simpleClass sampleMethod];
    return 0;
}
