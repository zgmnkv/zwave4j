package org.zwave4j;

/**
 * @author zagumennikov
 */
public class Notification {

    private NotificationType type;
    private ValueId valueId;
    private short aByte;
    private short event;

    public Notification(NotificationType type, ValueId valueId, short aByte, short event) {
        this.type = type;
        this.valueId = valueId;
        this.aByte = aByte;
        this.event = event;
    }

    public NotificationType getType() {
        return type;
    }

    public long getHomeId() {
        return valueId.getHomeId();
    }

    public short getNodeId() {
        return valueId.getNodeId();
    }

    public ValueId getValueId() {
        return valueId;
    }

    public short getGroupIdx() {
        assert NotificationType.GROUP.equals(type);
        return aByte;
    }

    public short getEvent() {
        assert NotificationType.NODE_EVENT.equals(type);
        return event;
    }

    public short getButtonId() {
        assert NotificationType.CREATE_BUTTON.equals(type) ||
                NotificationType.DELETE_BUTTON.equals(type) ||
                NotificationType.BUTTON_ON.equals(type) ||
                NotificationType.BUTTON_OFF.equals(type);
        return aByte;
    }

    public short getSceneId() {
        assert NotificationType.SCENE_EVENT.equals(type);
        return aByte;
    }

    public NotificationCode getNotification() {
        assert NotificationType.NOTIFICATION.equals(type);
        return NotificationCode.getNotificationCode(aByte);
    }

    public short getByte() {
        return aByte;
    }
}
