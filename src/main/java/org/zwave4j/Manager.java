package org.zwave4j;

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

    
    //Configuration
    public native void writeConfig(long homeId);

    
    //Drivers
    public native boolean addDriver(String path);

    public native boolean removeDriver(String path);

    public native short getControllerNodeId(long homeId);
    
    public native short getSUCNodeId(long homeId);
    
    public native boolean isPrimaryController(long homeId);
    
    public native boolean isStaticUpdateController(long homeId);
    
    public native boolean isBridgeController(long homeId);
    
    public native String getLibraryVersion(long homeId);
    
    public native String getLibraryTypeName(long homeId);
    
    public native int getSendQueueCount(long homeId);
    
    public native void logDriverStatistics(long homeId);
    
    public native ControllerInterface getControllerInterfaceType(long homeId);
    
    public native String getControllerPath(long homeId);
    

    
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


    //Button
    public native boolean pressButton(ValueId id);

    public native boolean releaseButton(ValueId id);


    //Climate Control Schedules
    public native short getNumSwitchPoints(ValueId id);

    public native boolean setSwitchPoint(ValueId id, short hours, short minutes, byte setback);

    public native boolean removeSwitchPoint(ValueId id, short hours, short minutes);

    public native void clearSwitchPoints(ValueId id);

    public native boolean getSwitchPoint(ValueId id, short idx, AtomicReference<Short> hours, AtomicReference<Short> minutes, AtomicReference<Byte> setback);

    
    //Switch all
    public native void switchAllOn(long homeId);

    public native void switchAllOff(long homeId);

    
    //Node configuration
    public native boolean setConfigParam(long homeId, short nodeId, short param, int value, short size);

    public native boolean setConfigParam(long homeId, short nodeId, short param, int value);

    public native void requestConfigParam(long homeId, short nodeId, short param);

    public native void requestAllConfigParams(long homeId, short nodeId);


    //Groups
    public native short getNumGroups(long homeId, short nodeId);

    public native long getAssociations(long homeId, short nodeId, short groupIdx, AtomicReference<short[]> associations);

    public native long getAssociationsWithInstance(long homeId, short nodeId, short groupIdx, AtomicReference<InstanceAssociation[]> associations);

    public native short getMaxAssociations(long homeId, short nodeId, short groupIdx);

    public native String getGroupLabel(long homeId, short nodeId, short groupIdx);

    public native void addAssociation(long homeId, short nodeId, short groupIdx, short targetNodeId, short instance);

    public void addAssociation(long homeId, short nodeId, short groupIdx, short targetNodeId)
    {
	addAssociation(homeId, nodeId, groupIdx, targetNodeId, (short)0);
    }

    public native void removeAssociation(long homeId, short nodeId, short groupIdx, short targetNodeId, short instance);

    public void removeAssociation(long homeId, short nodeId, short groupIdx, short targetNodeId)
    {
	removeAssociation(homeId, nodeId, groupIdx, targetNodeId, (short)0);
    }

    //Notifications
    public native void addWatcher(NotificationWatcher notificationWatcher, Object context);

    public native void removeWatcher(NotificationWatcher notificationWatcher, Object context);


    //Controller commands
    public native void resetController(long homeId);

    public native void softReset(long homeId);

    public native boolean beginControllerCommand(long homeId, ControllerCommand command);

    public native boolean beginControllerCommand(long homeId, ControllerCommand command, ControllerCallback callback);

    public native boolean beginControllerCommand(long homeId, ControllerCommand command, ControllerCallback callback, Object context);

    public native boolean beginControllerCommand(long homeId, ControllerCommand command, ControllerCallback callback, Object context, boolean highPower);

    public native boolean beginControllerCommand(long homeId, ControllerCommand command, ControllerCallback callback, Object context, boolean highPower, short nodeId);

    public native boolean beginControllerCommand(long homeId, ControllerCommand command, ControllerCallback callback, Object context, boolean highPower, short nodeId, short arg);

    public native boolean cancelControllerCommand(long homeId);


    //Network commands
    public native void testNetworkNode(long homeId, short nodeId, long count);

    public native void testNetwork(long homeId, long count);

    public native void healNetworkNode(long homeId, short nodeId, boolean doRR);

    public native void healNetwork(long homeId, boolean doRR);


    //Scene commands
    public native short getNumScenes();

    public native short getAllScenes(AtomicReference<short[]> sceneIds);

    public native void removeAllScenes(long homeId);

    public native short createScene();

    public native boolean removeScene(short sceneId);

    public native boolean addSceneValueAsBool(short sceneId, ValueId valueId, boolean value);

    public native boolean addSceneValueAsByte(short sceneId, ValueId valueId, short value);

    public native boolean addSceneValueAsFloat(short sceneId, ValueId valueId, float value);

    public native boolean addSceneValueAsInt(short sceneId, ValueId valueId, int value);

    public native boolean addSceneValueAsShort(short sceneId, ValueId valueId, short value);

    public native boolean addSceneValueAsString(short sceneId, ValueId valueId, String value);

    public native boolean addSceneValueListSelection(short sceneId, ValueId valueId, String value);

    public native boolean addSceneValueListSelection(short sceneId, ValueId valueId, int value);

    public native boolean removeSceneValue(short sceneId, ValueId valueId);

    public native int sceneGetValues(short sceneId, List<ValueId> value);

    public native boolean sceneGetValueAsBool(short sceneId, ValueId valueId, AtomicReference<Boolean> value);

    public native boolean sceneGetValueAsByte(short sceneId, ValueId valueId, AtomicReference<Short> value);

    public native boolean sceneGetValueAsFloat(short sceneId, ValueId valueId, AtomicReference<Float> value);

    public native boolean sceneGetValueAsInt(short sceneId, ValueId valueId, AtomicReference<Integer> value);

    public native boolean sceneGetValueAsShort(short sceneId, ValueId valueId, AtomicReference<Short> value);

    public native boolean sceneGetValueAsString(short sceneId, ValueId valueId, AtomicReference<String> value);

    public native boolean sceneGetValueListSelectionString(short sceneId, ValueId valueId, AtomicReference<String> value);

    public native boolean sceneGetValueListSelectionInt(short sceneId, ValueId valueId, AtomicReference<Integer> value);

    public native boolean setSceneValueAsBool(short sceneId, ValueId valueId, boolean value);

    public native boolean setSceneValueAsByte(short sceneId, ValueId valueId, short value);

    public native boolean setSceneValueAsFloat(short sceneId, ValueId valueId, float value);

    public native boolean setSceneValueAsInt(short sceneId, ValueId valueId, int value);

    public native boolean setSceneValueAsShort(short sceneId, ValueId valueId, short value);

    public native boolean setSceneValueAsString(short sceneId, ValueId valueId, String value);

    public native boolean setSceneValueListSelection(short sceneId, ValueId valueId, String value);

    public native boolean setSceneValueListSelection(short sceneId, ValueId valueId, int value);

    public native String getSceneLabel(short sceneId);

    public native void setSceneLabel(short sceneId, String value);

    public native boolean sceneExists(short sceneId);

    public native boolean activateScene(short sceneId);


    //Statistics
    public native void getDriverStatistics(long homeId, DriverData data);

    public native void getNodeStatistics(long homeId, short nodeId, NodeData data);
}
