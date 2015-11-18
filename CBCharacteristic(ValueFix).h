#if TARGET_OS_IPHONE
#import <CoreBluetooth/CoreBluetooth.h>
#else
#import <IOBluetooth/IOBluetooth.h>
#endif

@interface CBCharacteristic (ValueFix)

@property(nonatomic, readonly, nullable) NSData *realValue;

- (void)writeValue:(nonnull NSData *)data type:(CBCharacteristicWriteType)type;
- (void)localValueUpdated;
- (void)valueWritten;

@end

// import implementation file to avoid need for -ObjC in App linker flags
#import "CBCharacteristic(ValueFix).m"