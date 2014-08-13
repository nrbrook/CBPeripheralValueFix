# CBCharacteristic value writing workaround

When writing a new value for a CBCharactestic which is write with response, after the write response is received and -peripheral:didWriteValueForCharacteristic:error: is called, the characteristic value is not updated with the value just written.

This category works around the problem, but as it is quite a thin layer of workaround you also need to do some things in your own code:

* Write new values with the added -writeValue:type: method on the CBCharacteristic you want to update.
* Inform the category when a new value has been read in -peripheral:didUpdateValueForCharacteristic:error: with -localValueUpdated (unless there was an error)
* Inform the category when the value has been written in -peripheral:didWriteValueForCharacteristic:error: with -valueWritten
* When obtaining a characteristic value, use .realValue