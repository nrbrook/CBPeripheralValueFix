#import <CoreBluetooth/CoreBluetooth.h>

@interface CBCharacteristic (ValueFix)

@property(nonatomic, readonly) NSData *realValue;

- (void)writeValue:(NSData *)data type:(CBCharacteristicWriteType)type;
- (void)localValueUpdated;
- (void)valueWritten;

@end
