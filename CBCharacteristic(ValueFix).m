#import "CBCharacteristic(ValueFix).h"
#import <objc/runtime.h>

static void *TempDataKey;
static void *RealDataKey;

@implementation CBCharacteristic (ValueFix)

- (NSData *)realValue {
    NSData *d = objc_getAssociatedObject(self, &RealDataKey);
    return d ?: self.value;
}

- (void)writeValue:(NSData *)data type:(CBCharacteristicWriteType)type {
    if(type == CBCharacteristicWriteWithResponse) {
        objc_setAssociatedObject(self, &TempDataKey, data, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    [self.service.peripheral writeValue:data forCharacteristic:self type:type];
}

- (void)localValueUpdated {
    objc_setAssociatedObject(self, &RealDataKey, nil, 0);
}

- (void)valueWritten {
    NSData *d = objc_getAssociatedObject(self, &TempDataKey);
    if(d) {
        objc_setAssociatedObject(self, &RealDataKey, d, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        objc_setAssociatedObject(self, &TempDataKey, nil, 0);
    }
    
}

@end
