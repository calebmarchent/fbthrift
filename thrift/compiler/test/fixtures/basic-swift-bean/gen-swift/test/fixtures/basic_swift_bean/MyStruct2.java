/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basic_swift_bean;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;

import static com.google.common.base.MoreObjects.toStringHelper;

@SwiftGenerated
@ThriftStruct("MyStruct2")
public final class MyStruct2 {
    @ThriftConstructor
    public MyStruct2() {}

    private test.fixtures.basic_swift_bean.MyStruct1 myStruct1;
    private String myString;

    
    @ThriftField(value=1, name="myStruct1", requiredness=Requiredness.NONE)
    public test.fixtures.basic_swift_bean.MyStruct1 getMyStruct1() { return myStruct1; }
    
    @ThriftField
    public MyStruct2 setMyStruct1(test.fixtures.basic_swift_bean.MyStruct1 myStruct1) {
        this.myStruct1 = myStruct1;
        return this;
    }
        
    @ThriftField(value=2, name="myString", requiredness=Requiredness.NONE)
    public String getMyString() { return myString; }
    
    @ThriftField
    public MyStruct2 setMyString(String myString) {
        this.myString = myString;
        return this;
    }
    
    @Override
    public String toString() {
        return toStringHelper(this)
            .add("myStruct1", myStruct1)
            .add("myString", myString)
            .toString();
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        MyStruct2 other = (MyStruct2)o;
    
        return
            Objects.equals(myStruct1, other.myStruct1) &&
            Objects.equals(myString, other.myString) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            myStruct1,
            myString
        });
    }
    
}
