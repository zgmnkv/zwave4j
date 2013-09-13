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

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicReference;

/**
 * @author zagumennikov
 */
public class Manager {

    public static Manager instance;

    public static synchronized Manager create() {
        if (instance == null) {
            createNativeManager();
            instance = new Manager();
        }
        return instance;
    }

    public static Manager get() {
        return instance;
    }

    public static void destroy() {
        destroyNativeManager();
    }

    private static native void createNativeManager();

    private static native void destroyNativeManager();
    

    private List<NotificationWatcher> notificationWatchers = new ArrayList<>();

    
    //Configuration
    public native void writeConfig(long homeId);

    
    //Drivers
    public native boolean addDriver(String path);

    public native boolean removeDriver(String path);

    
    //Polling
    public native int getPollInterval();

    public native void setPollInterval(int milliseconds, boolean intervalBetweenPolls);

    public native boolean enablePoll(ValueId valueId, short intensity);
    
    public native boolean enablePoll(ValueId valueId);

    public native boolean disablePoll(ValueId valueId);

    public native boolean isPolled(ValueId valueId);

    public native void setPollIntensity(ValueId valueId, short intensity);

    
    //Node
    public native boolean refreshNodeInfo(long homeId, short nodeId);

    public native boolean requestNodeState(long homeId, short nodeId);

    public native boolean requestNodeDynamic(long homeId, short nodeId);

    public native boolean isNodeListeningDevice(long homeId, short nodeId);

    public native boolean isNodeFrequentListeningDevice(long homeId, short nodeId);

    public native boolean isNodeBeamingDevice(long homeId, short nodeId);

    public native boolean isNodeRoutingDevice(long homeId, short nodeId);

    public native boolean isNodeSecurityDevice(long homeId, short nodeId);

    public native long getNodeMaxBaudRate(long homeId, short nodeId);

    public native short getNodeVersion(long homeId, short nodeId);

    public native short getNodeSecurity(long homeId, short nodeId);

    public native short getNodeBasic(long homeId, short nodeId);

    public native void addAssociation(long homeId, short nodeId, short groupIdx, short targetNodeId);
    public native void testNetworkNode(long homeId, short nodeId, long count);
    public native void testNetwork(long homeId, long count);
    public native void healNetworkNode(long homeId, short nodeId, boolean doRR);
    public native void healNetwork(long homeId, boolean doRR);

    public native short getNodeGeneric(long homeId, short nodeId);

    public native short getNodeSpecific(long homeId, short nodeId);

    public native String getNodeType(long homeId, short nodeId);

    public native long getNodeNeighbors(long homeId, short nodeId, AtomicReference<short[]> nodeNeighbors);

    public native String getNodeManufacturerName(long homeId, short nodeId);

    public native String getNodeProductName(long homeId, short nodeId);

    public native String getNodeName(long homeId, short nodeId);

    public native String getNodeLocation(long homeId, short nodeId);

    public native String getNodeManufacturerId(long homeId, short nodeId);

    public native String getNodeProductType(long homeId, short nodeId);

    public native String getNodeProductId(long homeId, short nodeId);

    public native void setNodeManufacturerName(long homeId, short nodeId, String manufacturerName);

    public native void setNodeProductName(long homeId, short nodeId, String productName);

    public native void setNodeName(long homeId, short nodeId, String nodeName);

    public native void setNodeLocation(long homeId, short nodeId, String location);

    public native void setNodeOn(long homeId, short nodeId);

    public native void setNodeOff(long homeId, short nodeId);

    public native void setNodeLevel(long homeId, short nodeId, short level);

    public native boolean isNodeInfoReceived(long homeId, short nodeId);

    public native boolean getNodeClassInformation(long homeId, short nodeId, short commandClassId, String className, Short classVersion);

    public native boolean getNodeClassInformation(long homeId, short nodeId, short commandClassId, String className);

    public native boolean getNodeClassInformation(long homeId, short nodeId, short commandClassId);

    public native boolean isNodeAwake(long homeId, short nodeId);

    public native boolean isNodeFailed(long homeId, short nodeId);

    public native String getNodeQueryStage(long homeId, short nodeId);

    
    //Value
    public native String getValueLabel(ValueId id);

    public native void setValueLabel(ValueId id, String value);

    public native String getValueUnits(ValueId id);

    public native void setValueUnits(ValueId id, String value);

    public native String getValueHelp(ValueId id);

    public native void setValueHelp(ValueId id, String value);

    public native int getValueMin(ValueId id);

    public native int getValueMax(ValueId id);

    public native boolean isValueReadOnly(ValueId id);

    public native boolean isValueWriteOnly(ValueId id);

    public native boolean isValueSet(ValueId id);

    public native boolean isValuePolled(ValueId id);

    public native boolean getValueAsBool(ValueId id, AtomicReference<Boolean> value);

    public native boolean getValueAsByte(ValueId id, AtomicReference<Short> value);

    public native boolean getValueAsFloat(ValueId id, AtomicReference<Float> value);

    public native boolean getValueAsInt(ValueId id, AtomicReference<Integer> value);

    public native boolean getValueAsShort(ValueId id, AtomicReference<Short> value);

    public native boolean getValueAsString(ValueId id, AtomicReference<String> value);

    public native boolean getValueAsRaw(ValueId id, AtomicReference<short[]> value);

    public native boolean getValueListSelectionString(ValueId id, AtomicReference<String> value);

    public native boolean getValueListSelectionInt(ValueId id, AtomicReference<Integer> value);

    public native boolean getValueListItems(ValueId id, List<String> value);

    public native boolean getValueFloatPrecision(ValueId id, AtomicReference<Short> value);

    public native boolean setValueAsBool(ValueId id, boolean value);

    public native boolean setValueAsByte(ValueId id, short value);

    public native boolean setValueAsFloat(ValueId id, float value);

    public native boolean setValueAsInt(ValueId id, int value);

    public native boolean setValueAsShort(ValueId id, short value);

    public native boolean setValueAsRaw(ValueId id, short[] value);

    public native boolean setValueAsString(ValueId id, String value);

    public native boolean setValueListSelection(ValueId id, String selectedItem);

    public native boolean refreshValue(ValueId id);

    public native void setChangeVerified(ValueId id, boolean verify);

    public native boolean pressButton(ValueId id);

    public native boolean releaseButton(ValueId id);

    
    //Switch all
    public native void switchAllOn(long homeId);

    public native void switchAllOff(long homeId);

    
    //Node configuration
    public native boolean setConfigParam(long homeId, short nodeId, short param, int value, short size);

    public native boolean setConfigParam(long homeId, short nodeId, short param, int value);

    public native void requestConfigParam(long homeId, short nodeId, short param);

    public native void requestAllConfigParams(long homeId, short nodeId);

    public void addNotificationWatcher(NotificationWatcher notificationWatcher) {
        notificationWatchers.add(notificationWatcher);
    }

    public void removeNotificationWatcher(NotificationWatcher notificationWatcher) {
        notificationWatchers.remove(notificationWatcher);
    }
    

    /**
     * Called from native
     */
    private void fireNotificationWatchers(Notification notification) {
        for (NotificationWatcher notificationWatcher : notificationWatchers) {
            notificationWatcher.onNotification(notification);
        }
    }
}
