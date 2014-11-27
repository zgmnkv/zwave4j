/*
 * Copyright (c) 2013 Alexander Zagumennikov
 *
 * SOFTWARE NOTICE AND LICENSE
 *
 * This file is part of ZWave4J.
 *
 * ZWave4J is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ZWave4J is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ZWave4J.  If not, see <http://www.gnu.org/licenses/>.
 */

package org.zwave4j;

/**
 * @author zagumennikov
 */
public class Notification {

    private NotificationType type;
    private ValueId valueId;
    private short aByte;

    public Notification(NotificationType type, ValueId valueId, short aByte) {
        this.type = type;
        this.valueId = valueId;
        this.aByte = aByte;
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
        return aByte;
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
