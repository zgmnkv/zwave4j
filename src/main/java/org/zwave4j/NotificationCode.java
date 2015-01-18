package org.zwave4j;

public enum NotificationCode {
    MSG_COMPLETE,
    TIMEOUT,
    NO_OPERATION,
    AWAKE,
    SLEEP,
    DEAD,
    ALIVE,
    UNKNOWN;

    static NotificationCode getNotificationCode(short aByte) {
        switch (aByte) {
            case 0:
                return MSG_COMPLETE;
            case 1:
                return TIMEOUT;
            case 2:
                return NO_OPERATION;
            case 3:
                return AWAKE;
            case 4:
                return SLEEP;
            case 5:
                return DEAD;
            case 6:
                return ALIVE;
            default:
                return UNKNOWN;
        }
    }
}
