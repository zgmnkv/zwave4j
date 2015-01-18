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
public enum NotificationType {
    VALUE_ADDED,
    VALUE_REMOVED,
    VALUE_CHANGED,
    VALUE_REFRESHED,
    GROUP,
    NODE_NEW,
    NODE_ADDED,
    NODE_REMOVED,
    NODE_PROTOCOL_INFO,
    NODE_NAMING,
    NODE_EVENT,
    POLLING_DISABLED,
    POLLING_ENABLED,
    SCENE_EVENT,
    CREATE_BUTTON,
    DELETE_BUTTON,
    BUTTON_ON,
    BUTTON_OFF,
    DRIVER_READY,
    DRIVER_FAILED,
    DRIVER_RESET,
    DRIVER_REMOVED,
    ESSENTIAL_NODE_QUERIES_COMPLETE,
    NODE_QUERIES_COMPLETE,
    AWAKE_NODES_QUERIED,
    ALL_NODES_QUERIED_SOME_DEAD,
    ALL_NODES_QUERIED,
    NOTIFICATION
}
