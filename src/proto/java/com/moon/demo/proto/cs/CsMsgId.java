// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cs_msg_id.proto

package com.moon.demo.proto.cs;

public final class CsMsgId {
  private CsMsgId() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  /**
   * Protobuf enum {@code com.moon.demo.proto.cs.MsgId}
   */
  public enum MsgId
      implements com.google.protobuf.ProtocolMessageEnum {
    /**
     * <code>PLACE_HOLDER = 0;</code>
     */
    PLACE_HOLDER(0),
    /**
     * <code>MSG_ID_DEMO_1_REQ = 1000;</code>
     */
    MSG_ID_DEMO_1_REQ(1000),
    /**
     * <code>MSG_ID_DEMO_1_RSP = 1001;</code>
     */
    MSG_ID_DEMO_1_RSP(1001),
    /**
     * <code>MSG_ID_DEMO_2_REQ = 1002;</code>
     */
    MSG_ID_DEMO_2_REQ(1002),
    /**
     * <code>MSG_ID_DEMO_2_RSP = 1003;</code>
     */
    MSG_ID_DEMO_2_RSP(1003),
    /**
     * <code>MSG_ID_DEMO_3_REQ = 1004;</code>
     */
    MSG_ID_DEMO_3_REQ(1004),
    /**
     * <code>MSG_ID_DEMO_3_RSP = 1005;</code>
     */
    MSG_ID_DEMO_3_RSP(1005),
    /**
     * <code>MSG_ID_DEMO_4_REQ = 1006;</code>
     */
    MSG_ID_DEMO_4_REQ(1006),
    /**
     * <code>MSG_ID_DEMO_4_RSP = 1007;</code>
     */
    MSG_ID_DEMO_4_RSP(1007),
    /**
     * <code>MSG_ID_DEMO_5_REQ = 1008;</code>
     */
    MSG_ID_DEMO_5_REQ(1008),
    /**
     * <code>MSG_ID_DEMO_5_RSP = 1009;</code>
     */
    MSG_ID_DEMO_5_RSP(1009),
    /**
     * <code>MSG_ID_DEMO_6_REQ = 1010;</code>
     */
    MSG_ID_DEMO_6_REQ(1010),
    /**
     * <code>MSG_ID_DEMO_6_RSP = 1011;</code>
     */
    MSG_ID_DEMO_6_RSP(1011),
    UNRECOGNIZED(-1),
    ;

    /**
     * <code>PLACE_HOLDER = 0;</code>
     */
    public static final int PLACE_HOLDER_VALUE = 0;
    /**
     * <code>MSG_ID_DEMO_1_REQ = 1000;</code>
     */
    public static final int MSG_ID_DEMO_1_REQ_VALUE = 1000;
    /**
     * <code>MSG_ID_DEMO_1_RSP = 1001;</code>
     */
    public static final int MSG_ID_DEMO_1_RSP_VALUE = 1001;
    /**
     * <code>MSG_ID_DEMO_2_REQ = 1002;</code>
     */
    public static final int MSG_ID_DEMO_2_REQ_VALUE = 1002;
    /**
     * <code>MSG_ID_DEMO_2_RSP = 1003;</code>
     */
    public static final int MSG_ID_DEMO_2_RSP_VALUE = 1003;
    /**
     * <code>MSG_ID_DEMO_3_REQ = 1004;</code>
     */
    public static final int MSG_ID_DEMO_3_REQ_VALUE = 1004;
    /**
     * <code>MSG_ID_DEMO_3_RSP = 1005;</code>
     */
    public static final int MSG_ID_DEMO_3_RSP_VALUE = 1005;
    /**
     * <code>MSG_ID_DEMO_4_REQ = 1006;</code>
     */
    public static final int MSG_ID_DEMO_4_REQ_VALUE = 1006;
    /**
     * <code>MSG_ID_DEMO_4_RSP = 1007;</code>
     */
    public static final int MSG_ID_DEMO_4_RSP_VALUE = 1007;
    /**
     * <code>MSG_ID_DEMO_5_REQ = 1008;</code>
     */
    public static final int MSG_ID_DEMO_5_REQ_VALUE = 1008;
    /**
     * <code>MSG_ID_DEMO_5_RSP = 1009;</code>
     */
    public static final int MSG_ID_DEMO_5_RSP_VALUE = 1009;
    /**
     * <code>MSG_ID_DEMO_6_REQ = 1010;</code>
     */
    public static final int MSG_ID_DEMO_6_REQ_VALUE = 1010;
    /**
     * <code>MSG_ID_DEMO_6_RSP = 1011;</code>
     */
    public static final int MSG_ID_DEMO_6_RSP_VALUE = 1011;


    public final int getNumber() {
      if (this == UNRECOGNIZED) {
        throw new java.lang.IllegalArgumentException(
            "Can't get the number of an unknown enum value.");
      }
      return value;
    }

    /**
     * @deprecated Use {@link #forNumber(int)} instead.
     */
    @java.lang.Deprecated
    public static MsgId valueOf(int value) {
      return forNumber(value);
    }

    public static MsgId forNumber(int value) {
      switch (value) {
        case 0: return PLACE_HOLDER;
        case 1000: return MSG_ID_DEMO_1_REQ;
        case 1001: return MSG_ID_DEMO_1_RSP;
        case 1002: return MSG_ID_DEMO_2_REQ;
        case 1003: return MSG_ID_DEMO_2_RSP;
        case 1004: return MSG_ID_DEMO_3_REQ;
        case 1005: return MSG_ID_DEMO_3_RSP;
        case 1006: return MSG_ID_DEMO_4_REQ;
        case 1007: return MSG_ID_DEMO_4_RSP;
        case 1008: return MSG_ID_DEMO_5_REQ;
        case 1009: return MSG_ID_DEMO_5_RSP;
        case 1010: return MSG_ID_DEMO_6_REQ;
        case 1011: return MSG_ID_DEMO_6_RSP;
        default: return null;
      }
    }

    public static com.google.protobuf.Internal.EnumLiteMap<MsgId>
        internalGetValueMap() {
      return internalValueMap;
    }
    private static final com.google.protobuf.Internal.EnumLiteMap<
        MsgId> internalValueMap =
          new com.google.protobuf.Internal.EnumLiteMap<MsgId>() {
            public MsgId findValueByNumber(int number) {
              return MsgId.forNumber(number);
            }
          };

    public final com.google.protobuf.Descriptors.EnumValueDescriptor
        getValueDescriptor() {
      return getDescriptor().getValues().get(ordinal());
    }
    public final com.google.protobuf.Descriptors.EnumDescriptor
        getDescriptorForType() {
      return getDescriptor();
    }
    public static final com.google.protobuf.Descriptors.EnumDescriptor
        getDescriptor() {
      return com.moon.demo.proto.cs.CsMsgId.getDescriptor().getEnumTypes().get(0);
    }

    private static final MsgId[] VALUES = values();

    public static MsgId valueOf(
        com.google.protobuf.Descriptors.EnumValueDescriptor desc) {
      if (desc.getType() != getDescriptor()) {
        throw new java.lang.IllegalArgumentException(
          "EnumValueDescriptor is not for this type.");
      }
      if (desc.getIndex() == -1) {
        return UNRECOGNIZED;
      }
      return VALUES[desc.getIndex()];
    }

    private final int value;

    private MsgId(int value) {
      this.value = value;
    }

    // @@protoc_insertion_point(enum_scope:com.moon.demo.proto.cs.MsgId)
  }


  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\017cs_msg_id.proto\022\026com.moon.demo.proto.c" +
      "s*\271\002\n\005MsgId\022\020\n\014PLACE_HOLDER\020\000\022\026\n\021MSG_ID_" +
      "DEMO_1_REQ\020\350\007\022\026\n\021MSG_ID_DEMO_1_RSP\020\351\007\022\026\n" +
      "\021MSG_ID_DEMO_2_REQ\020\352\007\022\026\n\021MSG_ID_DEMO_2_R" +
      "SP\020\353\007\022\026\n\021MSG_ID_DEMO_3_REQ\020\354\007\022\026\n\021MSG_ID_" +
      "DEMO_3_RSP\020\355\007\022\026\n\021MSG_ID_DEMO_4_REQ\020\356\007\022\026\n" +
      "\021MSG_ID_DEMO_4_RSP\020\357\007\022\026\n\021MSG_ID_DEMO_5_R" +
      "EQ\020\360\007\022\026\n\021MSG_ID_DEMO_5_RSP\020\361\007\022\026\n\021MSG_ID_" +
      "DEMO_6_REQ\020\362\007\022\026\n\021MSG_ID_DEMO_6_RSP\020\363\007b\006p" +
      "roto3"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
        new com.google.protobuf.Descriptors.FileDescriptor.    InternalDescriptorAssigner() {
          public com.google.protobuf.ExtensionRegistry assignDescriptors(
              com.google.protobuf.Descriptors.FileDescriptor root) {
            descriptor = root;
            return null;
          }
        };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
        }, assigner);
  }

  // @@protoc_insertion_point(outer_class_scope)
}
