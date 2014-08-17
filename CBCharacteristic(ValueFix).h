#import <CoreBluetooth/CoreBluetooth.h>

@interface CBCharacteristic (ValueFix)

@property(nonatomic, readonly) NSData *realValue;

- (void)writeValue:(NSData *)data type:(CBCharacteristicWriteType)type;
- (void)localValueUpdated;
- (void)valueWritten;

@end

// import implementation file to avoid need for -ObjC in App linker flags
#import "CBCharacteristic(ValueFix).m"