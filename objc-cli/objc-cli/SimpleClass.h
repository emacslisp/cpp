//
//  SimpleClass.h
//  objc-cli
//
//  Created by ewu on 6/10/20.
//  Copyright © 2020 ewu. All rights reserved.
//

#ifndef SimpleClass_h
#define SimpleClass_h

#import <Foundation/Foundation.h>

@interface SimpleClass : NSObject

@property (readonly) NSString *firstName;
@property (readonly) NSString *lastName;

- (void)sampleMethod;
@end

#endif /* SimpleClass_h */
