/*
 Copyright (c) 2011, Tony Million.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE. 
 */

#import <Foundation/Foundation.h>
#import "TMHTTPBlockPrototypes.h"

@interface TMPOSTRequest : NSObject <NSURLConnectionDelegate, NSURLConnectionDataDelegate>

@property (nonatomic, assign) BOOL ignoresInvalidSSLCerts;
@property (nonatomic, assign) BOOL useBackground;

@property (nonatomic, readonly) NSData *postData;
@property (nonatomic, readonly) NSData *rawResponseData;
@property (nonatomic, strong, readonly) NSError *error;
@property (nonatomic, strong, readonly) NSHTTPURLResponse *response;
@property (nonatomic, assign, readonly) UIBackgroundTaskIdentifier    networkTask;

-(id)initWithURL:(NSURL*)url;

-(void)addPostValue:(id <NSObject>)value forKey:(NSString *)key;
-(void)setPostValue:(id <NSObject>)value forKey:(NSString *)key;

-(void)addData:(NSData *)data forKey:(NSString *)key;
-(void)setData:(NSData *)data forKey:(NSString *)key;

-(void)addData:(id)data withFileName:(NSString *)fileName andContentType:(NSString *)contentType forKey:(NSString *)key;
-(void)setData:(id)data withFileName:(NSString *)fileName andContentType:(NSString *)contentType forKey:(NSString *)key;

-(void)startRequest;
-(void)cancelRequest;
-(void)clearDelegatesAndCancelRequest;

-(void) setStartedBlock:(TMHTTPBasicBlock)startedBlock;
-(void) setCompletedBlock:(TMHTTPSuccessBlock)completedBlock;
-(void) setFailedBlock:(TMHTTPFailureBlock)failedBlock;
-(void) setCancelledBlock:(TMHTTPBasicBlock)cancelledBlock;
-(void) setDownloadProgressBlock:(TMHTTPProgressBlock)downloadProgressBlock;
-(void) setUploadProgressBlock:(TMHTTPProgressBlock)uploadProgressBlock;

@end
