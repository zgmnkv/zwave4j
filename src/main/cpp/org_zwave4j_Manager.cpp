#include <Manager.h>
#include <Notification.h>
#include <Group.h>
#include <org_zwave4j_Manager.h>
#include "init.h"

jobject getNotificationType(JNIEnv * env, OpenZWave::Notification::NotificationType ozwNotificationType)
{
	const char * name;
	switch(ozwNotificationType)
	{
	case OpenZWave::Notification::Type_ValueAdded:
		name = "VALUE_ADDED";
		break;
	case OpenZWave::Notification::Type_ValueRemoved:
		name = "VALUE_REMOVED";
		break;
	case OpenZWave::Notification::Type_ValueChanged:
		name = "VALUE_CHANGED";
		break;
	case OpenZWave::Notification::Type_ValueRefreshed:
		name = "VALUE_REFRESHED";
		break;
	case OpenZWave::Notification::Type_Group:
		name = "GROUP";
		break;
	case OpenZWave::Notification::Type_NodeNew:
		name = "NODE_NEW";
		break;
	case OpenZWave::Notification::Type_NodeAdded:
		name = "NODE_ADDED";
		break;
	case OpenZWave::Notification::Type_NodeRemoved:
		name = "NODE_REMOVED";
		break;
	case OpenZWave::Notification::Type_NodeProtocolInfo:
		name = "NODE_PROTOCOL_INFO";
		break;
	case OpenZWave::Notification::Type_NodeNaming:
		name = "NODE_NAMING";
		break;
	case OpenZWave::Notification::Type_NodeEvent:
		name = "NODE_EVENT";
		break;
	case OpenZWave::Notification::Type_PollingDisabled:
		name = "POLLING_DISABLED";
		break;
	case OpenZWave::Notification::Type_PollingEnabled:
		name = "POLLING_ENABLED";
		break;
	case OpenZWave::Notification::Type_SceneEvent:
		name = "SCENE_EVENT";
		break;
	case OpenZWave::Notification::Type_CreateButton:
		name = "CREATE_BUTTON";
		break;
	case OpenZWave::Notification::Type_DeleteButton:
		name = "DELETE_BUTTON";
		break;
	case OpenZWave::Notification::Type_ButtonOn:
		name = "BUTTON_ON";
		break;
	case OpenZWave::Notification::Type_ButtonOff:
		name = "BUTTON_OFF";
		break;
	case OpenZWave::Notification::Type_DriverReady:
		name = "DRIVER_READY";
		break;
	case OpenZWave::Notification::Type_DriverFailed:
		name = "DRIVER_FAILED";
		break;
	case OpenZWave::Notification::Type_DriverReset:
		name = "DRIVER_RESET";
		break;
	case OpenZWave::Notification::Type_EssentialNodeQueriesComplete:
		name = "ESSENTIAL_NODE_QUERIES_COMPLETE";
		break;
	case OpenZWave::Notification::Type_NodeQueriesComplete:
		name = "NODE_QUERIES_COMPLETE";
		break;
	case OpenZWave::Notification::Type_AwakeNodesQueried:
		name = "AWAKE_NODES_QUERIED";
		break;
	case OpenZWave::Notification::Type_AllNodesQueriedSomeDead:
		name = "ALL_NODES_QUERIED_SOME_DEAD";
		break;
	case OpenZWave::Notification::Type_AllNodesQueried:
		name = "ALL_NODES_QUERIED";
		break;
	case OpenZWave::Notification::Type_Notification:
		name = "NOTIFICATION";
		break;
	case OpenZWave::Notification::Type_ControllerCommand:
    	name = "CONTROLLER_COMMAND";
    	break;
    case OpenZWave::Notification::Type_DriverRemoved:
        name = "DRIVER_REMOVED";
        break;
    default:
        name = "NOT_SUPPORTED";
        break;
	}

	jclass clazz = findClass(env, "org/zwave4j/NotificationType");
	return env->GetStaticObjectField(clazz, env->GetStaticFieldID(clazz, name, "Lorg/zwave4j/NotificationType;"));
}

jobject getNotificationCode(JNIEnv * env, OpenZWave::Notification::NotificationCode ozwNotificationCode)
{
	const char * name;
	switch(ozwNotificationCode)
	{
	case OpenZWave::Notification::Code_MsgComplete:
		name = "MSG_COMPLETE";
		break;
	case OpenZWave::Notification::Code_Timeout:
		name = "TIMEOUT";
		break;
	case OpenZWave::Notification::Code_NoOperation:
		name = "NO_OPERATION";
		break;
	case OpenZWave::Notification::Code_Awake:
		name = "AWAKE";
		break;
	case OpenZWave::Notification::Code_Sleep:
		name = "SLEEP";
		break;
	case OpenZWave::Notification::Code_Dead:
		name = "DEAD";
		break;
	case OpenZWave::Notification::Code_Alive:
		name = "ALIVE";
		break;
	default:
        name = "NOT_SUPPORTED";
        break;
	}
	jclass clazz = findClass(env, "org/zwave4j/NotificationCode");
	return env->GetStaticObjectField(clazz, env->GetStaticFieldID(clazz, name, "Lorg/zwave4j/NotificationCode;"));
}

jobject getValueType(JNIEnv * env, OpenZWave::ValueID::ValueType ozwValueType)
{
	const char * name;
	switch(ozwValueType)
	{
	case OpenZWave::ValueID::ValueType_Bool:
		name = "BOOL";
		break;
	case OpenZWave::ValueID::ValueType_Byte:
		name = "BYTE";
		break;
	case OpenZWave::ValueID::ValueType_Decimal:
		name = "DECIMAL";
		break;
	case OpenZWave::ValueID::ValueType_Int:
		name = "INT";
		break;
	case OpenZWave::ValueID::ValueType_List:
		name = "LIST";
		break;
	case OpenZWave::ValueID::ValueType_Schedule:
		name = "SCHEDULE";
		break;
	case OpenZWave::ValueID::ValueType_Short:
		name = "SHORT";
		break;
	case OpenZWave::ValueID::ValueType_String:
		name = "STRING";
		break;
	case OpenZWave::ValueID::ValueType_Button:
		name = "BUTTON";
		break;
	case OpenZWave::ValueID::ValueType_Raw:
		name = "RAW";
		break;
    default:
        name = "NOT_SUPPORTED";
        break;
	}
	jclass clazz = findClass(env, "org/zwave4j/ValueType");
	return env->GetStaticObjectField(clazz, env->GetStaticFieldID(clazz, name, "Lorg/zwave4j/ValueType;"));
}

jobject getValueGenre(JNIEnv * env, OpenZWave::ValueID::ValueGenre ozwValueGenre)
{
	const char * name;
	switch(ozwValueGenre)
	{
	case OpenZWave::ValueID::ValueGenre_Basic:
		name = "BASIC";
		break;
	case OpenZWave::ValueID::ValueGenre_User:
		name = "USER";
		break;
	case OpenZWave::ValueID::ValueGenre_Config:
		name = "CONFIG";
		break;
	case OpenZWave::ValueID::ValueGenre_System:
		name = "SYSTEM";
		break;
	case OpenZWave::ValueID::ValueGenre_Count:
		name = "COUNT";
		break;
    default:
        name = "NOT_SUPPORTED";
        break;
	}
	jclass clazz = findClass(env, "org/zwave4j/ValueGenre");
	return env->GetStaticObjectField(clazz, env->GetStaticFieldID(clazz, name, "Lorg/zwave4j/ValueGenre;"));
}

jobject getControllerInterface(JNIEnv * env, OpenZWave::Driver::ControllerInterface ozwControllerInterface)
{
	const char * name;
	switch(ozwControllerInterface)
	{
    case OpenZWave::Driver::ControllerInterface_Unknown:
		name = "UNKNOWN";
		break;
	case OpenZWave::Driver::ControllerInterface_Serial:
		name = "SERIAL";
		break;
	case OpenZWave::Driver::ControllerInterface_Hid:
		name = "HID";
		break;
    default:
        name = "NOT_SUPPORTED";
        break;
	}
	jclass clazz = findClass(env, "org/zwave4j/ControllerInterface");
	return env->GetStaticObjectField(clazz, env->GetStaticFieldID(clazz, name, "Lorg/zwave4j/ControllerInterface;"));
}

jobject getControllerState(JNIEnv * env, OpenZWave::Driver::ControllerState ozwControllerState)
{
    const char * name;
	switch(ozwControllerState)
	{
    case OpenZWave::Driver::ControllerState_Normal:
		name = "NORMAL";
		break;
    case OpenZWave::Driver::ControllerState_Starting:
		name = "STARTING";
		break;		
    case OpenZWave::Driver::ControllerState_Cancel:
		name = "CANCEL";
		break;				
    case OpenZWave::Driver::ControllerState_Error:
		name = "ERROR";
		break;
    case OpenZWave::Driver::ControllerState_Waiting:
		name = "WAITING";
		break;	
    case OpenZWave::Driver::ControllerState_Sleeping:
		name = "SLEEPING";
		break;	
    case OpenZWave::Driver::ControllerState_InProgress:
		name = "IN_PROGRESS";
		break;		
    case OpenZWave::Driver::ControllerState_Completed:
		name = "COMPLETED";
		break;	   
    case OpenZWave::Driver::ControllerState_Failed:
		name = "FAILED";
		break;		
    case OpenZWave::Driver::ControllerState_NodeOK:
		name = "NODE_OK";
		break;			
    case OpenZWave::Driver::ControllerState_NodeFailed:
		name = "NODE_FAILED";
		break;
    default:
        name = "NOT_SUPPORTED";
        break;
	}
	jclass clazz = findClass(env, "org/zwave4j/ControllerState");
	return env->GetStaticObjectField(clazz, env->GetStaticFieldID(clazz, name, "Lorg/zwave4j/ControllerState;"));
}

jobject getControllerError(JNIEnv * env, OpenZWave::Driver::ControllerError ozwControllerError)
{
    const char * name;
	switch(ozwControllerError)
	{
    case OpenZWave::Driver::ControllerError_None:
		name = "NONE";
		break;
    case OpenZWave::Driver::ControllerError_ButtonNotFound:
		name = "BUTTON_NOT_FOUND";
		break;			
    case OpenZWave::Driver::ControllerError_NodeNotFound:
		name = "NODE_NOT_FOUND";
		break;			
    case OpenZWave::Driver::ControllerError_NotBridge:
		name = "NOT_BRIDGE";
		break;	
    case OpenZWave::Driver::ControllerError_NotSUC:
		name = "NOT_SUC";
		break;
    case OpenZWave::Driver::ControllerError_NotSecondary:
		name = "NOT_SECONDARY";
		break;
    case OpenZWave::Driver::ControllerError_NotPrimary:
		name = "NOT_PRIMARY";
		break;
    case OpenZWave::Driver::ControllerError_IsPrimary:
		name = "IS_PRIMARY";
		break;
    case OpenZWave::Driver::ControllerError_NotFound:
		name = "NOT_FOUND";
		break;
    case OpenZWave::Driver::ControllerError_Busy:
		name = "BUSY";
		break;
    case OpenZWave::Driver::ControllerError_Failed:
		name = "FAILED";
		break;
    case OpenZWave::Driver::ControllerError_Disabled:
		name = "DISABLED";
		break;
    case OpenZWave::Driver::ControllerError_Overflow:
		name = "OVERFLOW";
		break;
    default:
        name = "NOT_SUPPORTED";
        break;
	}
	jclass clazz = findClass(env, "org/zwave4j/ControllerError");
	return env->GetStaticObjectField(clazz, env->GetStaticFieldID(clazz, name, "Lorg/zwave4j/ControllerError;"));
}

jobject getValueId(JNIEnv * env, OpenZWave::ValueID const * ozwValueId)
{
	jclass clazz = findClass(env, "org/zwave4j/ValueId");
	return env->NewObject(
		clazz,
		env->GetMethodID(clazz, "<init>", "(JSLorg/zwave4j/ValueGenre;SSSLorg/zwave4j/ValueType;)V"),
		getJlong(ozwValueId->GetHomeId()),
		getJshort(ozwValueId->GetNodeId()),
		getValueGenre(env, ozwValueId->GetGenre()),
		getJshort(ozwValueId->GetCommandClassId()),
		getJshort(ozwValueId->GetInstance()),
		getJshort(ozwValueId->GetIndex()),
		getValueType(env, ozwValueId->GetType())
	);
}

jobject getNotification(JNIEnv * env, OpenZWave::Notification const * ozwNotification)
{
	jclass clazz = findClass(env, "org/zwave4j/Notification");
	return env->NewObject(
		clazz,
		env->GetMethodID(clazz, "<init>", "(Lorg/zwave4j/NotificationType;Lorg/zwave4j/ValueId;S)V"),
		getNotificationType(env, ozwNotification->GetType()),
		getValueId(env, &ozwNotification->GetValueID()),
		getJshort(ozwNotification->GetByte())
	);
}

jobject getCommandClassData(JNIEnv * env, OpenZWave::Node::CommandClassData const * ozwCommandClassData) {
    jclass clazz = findClass(env, "org/zwave4j/CommandClassData");
    return env->NewObject(
        clazz,
        env->GetMethodID(clazz, "<init>", "(SJJ)V"),
        getJshort(ozwCommandClassData->m_commandClassId),
        getJlong(ozwCommandClassData->m_sentCnt),
        getJlong(ozwCommandClassData->m_receivedCnt)
    );
}

OpenZWave::ValueID::ValueType getOzwValueType(JNIEnv * env, jobject valueType)
{
	jstring name = (jstring) env->CallObjectMethod(
		valueType, env->GetMethodID(findClass(env, "org/zwave4j/ValueType"), "name", "()Ljava/lang/String;")
	);
	const char * nameChars = env->GetStringUTFChars(name, NULL);
	OpenZWave::ValueID::ValueType ozwValueType;
	if (strcmp(nameChars, "BOOL") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Bool;
	else if (strcmp(nameChars, "BYTE") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Byte;
	else if (strcmp(nameChars, "DECIMAL") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Decimal;
	else if (strcmp(nameChars, "INT") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Int;
	else if (strcmp(nameChars, "LIST") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_List;
	else if (strcmp(nameChars, "SCHEDULE") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Schedule;
	else if (strcmp(nameChars, "SHORT") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Short;
	else if (strcmp(nameChars, "STRING") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_String;
	else if (strcmp(nameChars, "BUTTON") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Button;
	else if (strcmp(nameChars, "RAW") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Raw;

	env->ReleaseStringUTFChars(name, nameChars);
	return ozwValueType;
}

OpenZWave::ValueID::ValueGenre getOzwValueGenre(JNIEnv * env, jobject valueGenre)
{
	jstring name = (jstring) env->CallObjectMethod(
		valueGenre, env->GetMethodID(findClass(env, "org/zwave4j/ValueGenre"), "name", "()Ljava/lang/String;")
	);
	const char * nameChars = env->GetStringUTFChars(name, NULL);
	OpenZWave::ValueID::ValueGenre ozwValueGenre;
	if (strcmp(nameChars, "BASIC") == 0)
		ozwValueGenre = OpenZWave::ValueID::ValueGenre_Basic;
	else if (strcmp(nameChars, "USER") == 0)
		ozwValueGenre = OpenZWave::ValueID::ValueGenre_User;
	else if (strcmp(nameChars, "CONFIG") == 0)
		ozwValueGenre = OpenZWave::ValueID::ValueGenre_Config;
	else if (strcmp(nameChars, "SYSTEM") == 0)
		ozwValueGenre = OpenZWave::ValueID::ValueGenre_System;
	else if (strcmp(nameChars, "COUNT") == 0)
		ozwValueGenre = OpenZWave::ValueID::ValueGenre_Count;

	env->ReleaseStringUTFChars(name, nameChars);
	return ozwValueGenre;
}

OpenZWave::Driver::ControllerCommand getOzwControllerCommand(JNIEnv * env, jobject controllerCommand)
{
    jstring name = (jstring) env->CallObjectMethod(
		controllerCommand, env->GetMethodID(findClass(env, "org/zwave4j/ControllerCommand"), "name", "()Ljava/lang/String;")
	);
	const char * nameChars = env->GetStringUTFChars(name, NULL);
	OpenZWave::Driver::ControllerCommand ozwControllerCommand;
	if (strcmp(nameChars, "NONE") == 0)
		ozwControllerCommand = OpenZWave::Driver::ControllerCommand_None;
    else if (strcmp(nameChars, "ADD_DEVICE") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_AddDevice;
    else if (strcmp(nameChars, "CREATE_NEW_PRIMARY") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_CreateNewPrimary;
    else if (strcmp(nameChars, "RECEIVE_CONFIGURATION") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_ReceiveConfiguration;
    else if (strcmp(nameChars, "REMOVE_DEVICE") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_RemoveDevice;
    else if (strcmp(nameChars, "REMOVE_FAILED_NODE") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_RemoveFailedNode;
    else if (strcmp(nameChars, "HAS_NODE_FAILED") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_HasNodeFailed;
    else if (strcmp(nameChars, "REPLACE_FAILED_NODE") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_ReplaceFailedNode;
    else if (strcmp(nameChars, "TRANSFER_PRIMARY_ROLE") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_TransferPrimaryRole;
    else if (strcmp(nameChars, "REQUEST_NETWORK_UPDATE") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_RequestNetworkUpdate;
    else if (strcmp(nameChars, "REQUEST_NODE_NEIGHBOR_UPDATE") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_RequestNodeNeighborUpdate;
    else if (strcmp(nameChars, "ASSIGN_RETURN_ROUTE") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_AssignReturnRoute;
    else if (strcmp(nameChars, "DELETE_ALL_RETURN_ROUTES") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_DeleteAllReturnRoutes;
    else if (strcmp(nameChars, "SEND_NODE_INFORMATION") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_SendNodeInformation;
    else if (strcmp(nameChars, "REPLICATION_SEND") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_ReplicationSend;
    else if (strcmp(nameChars, "CREATE_BUTTON") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_CreateButton;
    else if (strcmp(nameChars, "DELETE_BUTTON") == 0)
        ozwControllerCommand = OpenZWave::Driver::ControllerCommand_DeleteButton;

	env->ReleaseStringUTFChars(name, nameChars);
	return ozwControllerCommand;
}

OpenZWave::ValueID getOzwValueId(JNIEnv * env, jobject valueId)
{
	jclass clazz = findClass(env, "org/zwave4j/ValueId");
	return OpenZWave::ValueID(
		getUint32(env->CallLongMethod(valueId, env->GetMethodID(clazz, "getHomeId", "()J"))),
		getUint8(env->CallShortMethod(valueId, env->GetMethodID(clazz, "getNodeId", "()S"))),
		getOzwValueGenre(
			env, env->CallObjectMethod(valueId, env->GetMethodID(clazz, "getGenre", "()Lorg/zwave4j/ValueGenre;"))
		),
		getUint8(env->CallShortMethod(valueId, env->GetMethodID(clazz, "getCommandClassId", "()S"))),
		getUint8(env->CallShortMethod(valueId, env->GetMethodID(clazz, "getInstance", "()S"))),
		getUint8(env->CallShortMethod(valueId, env->GetMethodID(clazz, "getIndex", "()S"))),
		getOzwValueType(
			env, env->CallObjectMethod(valueId, env->GetMethodID(clazz, "getType", "()Lorg/zwave4j/ValueType;"))
		)
	);
}

OpenZWave::Node::CommandClassData getOzwCommandClassData(JNIEnv * env, jobject commandClassData)
{
    jclass clazz = findClass(env, "org/zwave4j/CommandClassData");
    OpenZWave::Node::CommandClassData ozwCommandClassData = OpenZWave::Node::CommandClassData();
    ozwCommandClassData.m_commandClassId = env->CallShortMethod(commandClassData, env->GetMethodID(clazz, "getCommandClassId", "()S"));
    ozwCommandClassData.m_sentCnt = env->CallLongMethod(commandClassData, env->GetMethodID(clazz, "getSentCnt", "()J"));
    ozwCommandClassData.m_receivedCnt = env->CallLongMethod(commandClassData, env->GetMethodID(clazz, "getReceivedCnt", "()J"));
    return ozwCommandClassData;
}

struct sameObjectPairComparator
{
    bool operator()(const std::pair<jobject, jobject>& o1, const std::pair<jobject, jobject>& o2) const
    {
        JNIEnv * env;
        jvm->GetEnv((void **) &env, JNI_VERSION_1_6);
        return (env->IsSameObject(o1.first, o2.first) && env->IsSameObject(o1.second, o2.second)) < true;
    }
};

std::map<std::pair<jobject, jobject>, std::pair<jobject, jobject> *, sameObjectPairComparator> notificationWatchers;

void onNotification(OpenZWave::Notification const * ozwNotification, void * context)
{
	JNIEnv * env;
    int getEnvResult = jvm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (getEnvResult == JNI_EDETACHED)
    {
        jvm->AttachCurrentThread((void **) &env, NULL);
    }

    std::pair<jobject, jobject> * pair = (std::pair<jobject, jobject> *) context;

	env->CallVoidMethod(
		pair->first,
		env->GetMethodID(findClass(env, "org/zwave4j/NotificationWatcher"), "onNotification", "(Lorg/zwave4j/Notification;Ljava/lang/Object;)V"),
		getNotification(env, ozwNotification),
		pair->second
	);

	jvm->DetachCurrentThread();
}

void onControllerCallback(OpenZWave::Driver::ControllerState ozwState, OpenZWave::Driver::ControllerError ozwErr, void* context)
{
    JNIEnv * env;
    int getEnvResult = jvm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (getEnvResult == JNI_EDETACHED)
    {
        jvm->AttachCurrentThread((void **) &env, NULL);
    }

    std::pair<jobject, jobject> * pair = (std::pair<jobject, jobject> *) context;

    env->CallVoidMethod(
		pair->first,
		env->GetMethodID(findClass(env, "org/zwave4j/ControllerCallback"), "onCallback", "(Lorg/zwave4j/ControllerState;Lorg/zwave4j/ControllerError;Ljava/lang/Object;)V"),
		getControllerState(env, ozwState),
		getControllerError(env, ozwErr),
		pair->second
	);

    if (
            ozwState == OpenZWave::Driver::ControllerState_Normal ||
            ozwState == OpenZWave::Driver::ControllerState_Cancel ||
            ozwState == OpenZWave::Driver::ControllerState_Error ||
            ozwState == OpenZWave::Driver::ControllerState_Completed ||
            ozwState == OpenZWave::Driver::ControllerState_Failed ||
            ozwState == OpenZWave::Driver::ControllerState_NodeOK ||
            ozwState == OpenZWave::Driver::ControllerState_NodeFailed
    ) {
        env->DeleteGlobalRef(pair->first);
        if (pair->second != NULL) {
            env->DeleteGlobalRef(pair->second);
        }
        delete pair;
    }

	jvm->DetachCurrentThread();
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    createNativeManager
 * Signature: ()V;
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_createNativeManager
  (JNIEnv * env, jclass clazz)
{
	OpenZWave::Manager::Create();
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    destroyNativeManager
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_destroyNativeManager
  (JNIEnv * env, jclass clazz)
{
	OpenZWave::Manager::Destroy();
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    writeConfig
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_writeConfig
  (JNIEnv * env, jobject object, jlong homeId)
{
	OpenZWave::Manager::Get()->WriteConfig(getUint32(homeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addDriver
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_addDriver
  (JNIEnv * env, jobject object, jstring path)
{
	const char * pathChars = env->GetStringUTFChars(path, NULL);
	jboolean result = getJboolean(OpenZWave::Manager::Get()->AddDriver(std::string(pathChars)));
	env->ReleaseStringUTFChars(path, pathChars);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    removeDriver
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_removeDriver
  (JNIEnv * env, jobject object, jstring path)
{
	const char * pathChars = env->GetStringUTFChars(path, NULL);
	jboolean result = getJboolean(OpenZWave::Manager::Get()->RemoveDriver(std::string(pathChars)));
	env->ReleaseStringUTFChars(path, pathChars);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getControllerNodeId
 * Signature: (J)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getControllerNodeId
  (JNIEnv * env, jobject object, jlong homeId)
{
    return getJshort(OpenZWave::Manager::Get()->GetControllerNodeId(getUint32(homeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getSUCNodeId
 * Signature: (J)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getSUCNodeId
  (JNIEnv * env, jobject object, jlong homeId)
{
    return getJshort(OpenZWave::Manager::Get()->GetSUCNodeId(getUint32(homeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isPrimaryController
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isPrimaryController
  (JNIEnv * env, jobject object, jlong homeId)
{
    return getJboolean(OpenZWave::Manager::Get()->IsPrimaryController(getUint32(homeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isStaticUpdateController
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isStaticUpdateController
  (JNIEnv * env, jobject object, jlong homeId)
{
    return getJboolean(OpenZWave::Manager::Get()->IsStaticUpdateController(getUint32(homeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isBridgeController
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isBridgeController
  (JNIEnv * env, jobject object, jlong homeId)
{
    return getJboolean(OpenZWave::Manager::Get()->IsBridgeController(getUint32(homeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getLibraryVersion
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getLibraryVersion
  (JNIEnv * env, jobject object, jlong homeId)
{
    return env->NewStringUTF(OpenZWave::Manager::Get()->GetLibraryVersion(getUint32(homeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getLibraryTypeName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getLibraryTypeName
  (JNIEnv * env, jobject object, jlong homeId)
{
    return env->NewStringUTF(OpenZWave::Manager::Get()->GetLibraryTypeName(getUint32(homeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getSendQueueCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_zwave4j_Manager_getSendQueueCount
  (JNIEnv * env, jobject object, jlong homeId)
{
    return getJint(OpenZWave::Manager::Get()->GetSendQueueCount(getUint32(homeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    logDriverStatistics
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_logDriverStatistics
  (JNIEnv * env, jobject object, jlong homeId)
{
    OpenZWave::Manager::Get()->LogDriverStatistics(getUint32(homeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getControllerInterfaceType
 * Signature: (J)Lorg/zwave4j/ControllerInterface;
 */
JNIEXPORT jobject JNICALL Java_org_zwave4j_Manager_getControllerInterfaceType
  (JNIEnv * env, jobject object, jlong homeId)
{
    return getControllerInterface(env, OpenZWave::Manager::Get()->GetControllerInterfaceType(getUint32(homeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getControllerPath
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getControllerPath
  (JNIEnv * env, jobject object, jlong homeId)
{
    return env->NewStringUTF(OpenZWave::Manager::Get()->GetControllerPath(getUint32(homeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getPollInterval
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_zwave4j_Manager_getPollInterval
  (JNIEnv * env, jobject object)
{
	return OpenZWave::Manager::Get()->GetPollInterval();
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setPollInterval
 * Signature: (IZ)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setPollInterval
  (JNIEnv * env, jobject object, jint milliseconds, jboolean intervalBetweenPolls)
{
	OpenZWave::Manager::Get()->SetPollInterval(milliseconds, getBool(intervalBetweenPolls));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    enablePoll
 * Signature: (Lorg/zwave4j/ValueId;S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_enablePoll__Lorg_zwave4j_ValueId_2S
  (JNIEnv * env, jobject object, jobject valueId, jshort intensity)
{
	return getJboolean(OpenZWave::Manager::Get()->EnablePoll(getOzwValueId(env, valueId), getUint8(intensity)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    enablePoll
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_enablePoll__Lorg_zwave4j_ValueId_2
  (JNIEnv * env, jobject object, jobject valueId)
{
    return getJboolean(OpenZWave::Manager::Get()->EnablePoll(getOzwValueId(env, valueId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    disablePoll
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_disablePoll
  (JNIEnv * env, jobject object, jobject valueId)
{
	return getJboolean(OpenZWave::Manager::Get()->DisablePoll(getOzwValueId(env, valueId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isPolled
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isPolled
  (JNIEnv * env, jobject object, jobject valueId)
{
	return getJboolean(OpenZWave::Manager::Get()->isPolled(getOzwValueId(env, valueId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setPollIntensity
 * Signature: (Lorg/zwave4j/ValueId;S)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setPollIntensity
  (JNIEnv * env, jobject object, jobject valueId, jshort intensity)
{
	OpenZWave::Manager::Get()->SetPollIntensity(getOzwValueId(env, valueId), getUint8(intensity));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    refreshNodeInfo
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_refreshNodeInfo
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return getJboolean(OpenZWave::Manager::Get()->RefreshNodeInfo(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    requestNodeState
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_requestNodeState
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return getJboolean(OpenZWave::Manager::Get()->RequestNodeState(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    requestNodeDynamic
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_requestNodeDynamic
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return getJboolean(OpenZWave::Manager::Get()->RequestNodeDynamic(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeListeningDevice
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeListeningDevice
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsNodeListeningDevice(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeFrequentListeningDevice
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeFrequentListeningDevice
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsNodeFrequentListeningDevice(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeBeamingDevice
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeBeamingDevice
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsNodeBeamingDevice(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeRoutingDevice
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeRoutingDevice
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsNodeRoutingDevice(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeSecurityDevice
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeSecurityDevice
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsNodeSecurityDevice(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeMaxBaudRate
 * Signature: (JS)J
 */
JNIEXPORT jlong JNICALL Java_org_zwave4j_Manager_getNodeMaxBaudRate
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeMaxBaudRate(getUint32(homeId), getUint8(nodeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeVersion
 * Signature: (JS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNodeVersion
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeVersion(getUint32(homeId), getUint8(nodeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeSecurity
 * Signature: (JS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNodeSecurity
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeSecurity(getUint32(homeId), getUint8(nodeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeBasic
 * Signature: (JS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNodeBasic
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeBasic(getUint32(homeId), getUint8(nodeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeGeneric
 * Signature: (JS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNodeGeneric
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeGeneric(getUint32(homeId), getUint8(nodeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeSpecific
 * Signature: (JS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNodeSpecific
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeSpecific(getUint32(homeId), getUint8(nodeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeType
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeType
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeType(getUint32(homeId), getUint8(nodeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeNeighbors
 * Signature: (JSLjava/util/concurrent/atomic/AtomicReference;)J
 */
JNIEXPORT jlong JNICALL Java_org_zwave4j_Manager_getNodeNeighbors
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jobject nodeNeighbors)
{
	uint8 * ozwNodeNeighbors;
	uint32 neighborsAmount = OpenZWave::Manager::Get()->GetNodeNeighbors(getUint32(homeId), getUint8(nodeId), &ozwNodeNeighbors);

    jshortArray neighborsArray = env->NewShortArray(getJsize(neighborsAmount));
	jshort * neighborsArrayElements = env->GetShortArrayElements(neighborsArray, NULL);
	for (uint32 i = 0; i < neighborsAmount; ++i)
	{
	    neighborsArrayElements[i] = getJshort(ozwNodeNeighbors[i]);
	}
	env->ReleaseShortArrayElements(neighborsArray, neighborsArrayElements, 0);

	delete [] ozwNodeNeighbors;

	env->CallVoidMethod(
		nodeNeighbors,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		neighborsArray
	);
	return neighborsAmount;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeManufacturerName
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeManufacturerName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeManufacturerName(getUint32(homeId), getUint8(nodeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeProductName
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeProductName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeProductName(getUint32(homeId), getUint8(nodeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeName
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeName(getUint32(homeId), getUint8(nodeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeLocation
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeLocation
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeLocation(getUint32(homeId), getUint8(nodeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeManufacturerId
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeManufacturerId
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeManufacturerId(getUint32(homeId), getUint8(nodeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeProductType
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeProductType
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeProductType(getUint32(homeId), getUint8(nodeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeProductId
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeProductId
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeProductId(getUint32(homeId), getUint8(nodeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeManufacturerName
 * Signature: (JSLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeManufacturerName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jstring manufacturerName)
{
	const char * manufacturerNameChars = env->GetStringUTFChars(manufacturerName, NULL);
	OpenZWave::Manager::Get()->SetNodeManufacturerName(getUint32(homeId), getUint8(nodeId), std::string(manufacturerNameChars));
	env->ReleaseStringUTFChars(manufacturerName, manufacturerNameChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeProductName
 * Signature: (JSLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeProductName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jstring productName)
{
	const char * productNameChars = env->GetStringUTFChars(productName, NULL);
	OpenZWave::Manager::Get()->SetNodeProductName(getUint32(homeId), getUint8(nodeId), std::string(productNameChars));
	env->ReleaseStringUTFChars(productName, productNameChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeName
 * Signature: (JSLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jstring nodeName)
{
	const char * nodeNameChars = env->GetStringUTFChars(nodeName, NULL);
	OpenZWave::Manager::Get()->SetNodeName(getUint32(homeId), getUint8(nodeId), std::string(nodeNameChars));
	env->ReleaseStringUTFChars(nodeName, nodeNameChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeLocation
 * Signature: (JSLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeLocation
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jstring location)
{
	const char * locationChars = env->GetStringUTFChars(location, NULL);
	OpenZWave::Manager::Get()->SetNodeLocation(getUint32(homeId), getUint8(nodeId), std::string(locationChars));
	env->ReleaseStringUTFChars(location, locationChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeOn
 * Signature: (JS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeOn
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	OpenZWave::Manager::Get()->SetNodeOn(getUint32(homeId), getUint8(nodeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeOff
 * Signature: (JS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeOff
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	OpenZWave::Manager::Get()->SetNodeOff(getUint32(homeId), getUint8(nodeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeLevel
 * Signature: (JSS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeLevel
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort level)
{
	OpenZWave::Manager::Get()->SetNodeLevel(getUint32(homeId), getUint8(nodeId), getUint8(level));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeInfoReceived
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeInfoReceived
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsNodeInfoReceived(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeClassInformation
 * Signature: (JSSLjava/lang/String;Ljava/lang/Short;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getNodeClassInformation__JSSLjava_lang_String_2Ljava_lang_Short_2
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort commandClassId, jstring className, jobject classVersion)
{
	const char * classNameChars;
	std::string classNameString;
	if (className != NULL)
	{
		classNameChars = env->GetStringUTFChars(className, NULL);
		classNameString = classNameChars;
	}
	uint8 ozwClassVersion;
	if (classVersion != NULL)
	{
		ozwClassVersion = getUint8(env->CallShortMethod(classVersion, env->GetMethodID(findClass(env, "java/lang/Short"), "shortValue", "()S")));
	}
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetNodeClassInformation(
	    getUint32(homeId),
	    getUint8(nodeId),
	    getUint8(commandClassId),
	    (className != NULL) ? &classNameString : NULL,
	    (classVersion != NULL) ? &ozwClassVersion : NULL
    ));

	if (className != NULL)
	{
		env->ReleaseStringUTFChars(className, classNameChars);
	}
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeClassInformation
 * Signature: (JSSLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getNodeClassInformation__JSSLjava_lang_String_2
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort commandClassId, jstring className)
{
    const char * classNameChars;
	std::string classNameString;
	if (className != NULL)
	{
		classNameChars = env->GetStringUTFChars(className, NULL);
		classNameString = classNameChars;
	}
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetNodeClassInformation(
	    getUint32(homeId),
	    getUint8(nodeId),
	    getUint8(commandClassId),
	    (className != NULL) ? &classNameString : NULL
    ));

	if (className != NULL)
	{
		env->ReleaseStringUTFChars(className, classNameChars);
	}
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeClassInformation
 * Signature: (JSS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getNodeClassInformation__JSS
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort commandClassId)
{
    return getJboolean(OpenZWave::Manager::Get()->GetNodeClassInformation(
	    getUint32(homeId),
	    getUint8(nodeId),
	    getUint8(commandClassId)
    ));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeAwake
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeAwake
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsNodeAwake(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeFailed
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeFailed
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsNodeFailed(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeQueryStage
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeQueryStage
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeQueryStage(getUint32(homeId), getUint8(nodeId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueLabel
 * Signature: (Lorg/zwave4j/ValueId;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getValueLabel
  (JNIEnv * env, jobject object, jobject valueId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetValueLabel(getOzwValueId(env, valueId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueLabel
 * Signature: (Lorg/zwave4j/ValueId;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setValueLabel
  (JNIEnv * env, jobject object, jobject valueId, jstring value)
{
	const char * valueChars = env->GetStringUTFChars(value, NULL);
	OpenZWave::Manager::Get()->SetValueLabel(getOzwValueId(env, valueId), std::string(valueChars));
	env->ReleaseStringUTFChars(value, valueChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueUnits
 * Signature: (Lorg/zwave4j/ValueId;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getValueUnits
  (JNIEnv * env, jobject object, jobject valueId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetValueUnits(getOzwValueId(env, valueId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueUnits
 * Signature: (Lorg/zwave4j/ValueId;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setValueUnits
  (JNIEnv * env, jobject object, jobject valueId, jstring value)
{
	const char * valueChars = env->GetStringUTFChars(value, NULL);
	OpenZWave::Manager::Get()->SetValueUnits(getOzwValueId(env, valueId), std::string(valueChars));
	env->ReleaseStringUTFChars(value, valueChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueHelp
 * Signature: (Lorg/zwave4j/ValueId;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getValueHelp
  (JNIEnv * env, jobject object, jobject valueId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetValueHelp(getOzwValueId(env, valueId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueHelp
 * Signature: (Lorg/zwave4j/ValueId;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setValueHelp
  (JNIEnv * env, jobject object, jobject valueId, jstring value)
{
	const char * valueChars = env->GetStringUTFChars(value, NULL);
	OpenZWave::Manager::Get()->SetValueHelp(getOzwValueId(env, valueId), std::string(valueChars));
	env->ReleaseStringUTFChars(value, valueChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueMin
 * Signature: (Lorg/zwave4j/ValueId;)I
 */
JNIEXPORT jint JNICALL Java_org_zwave4j_Manager_getValueMin
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->GetValueMin(getOzwValueId(env, valueId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueMax
 * Signature: (Lorg/zwave4j/ValueId;)I
 */
JNIEXPORT jint JNICALL Java_org_zwave4j_Manager_getValueMax
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->GetValueMax(getOzwValueId(env, valueId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isValueReadOnly
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isValueReadOnly
  (JNIEnv * env, jobject object, jobject valueId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsValueReadOnly(getOzwValueId(env, valueId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isValueWriteOnly
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isValueWriteOnly
  (JNIEnv * env, jobject object, jobject valueId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsValueWriteOnly(getOzwValueId(env, valueId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isValueSet
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isValueSet
  (JNIEnv * env, jobject object, jobject valueId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsValueSet(getOzwValueId(env, valueId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isValuePolled
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isValuePolled
  (JNIEnv * env, jobject object, jobject valueId)
{
	return getJboolean(OpenZWave::Manager::Get()->IsValuePolled(getOzwValueId(env, valueId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsBool
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsBool
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	bool ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetValueAsBool(getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Boolean"),
			env->GetMethodID(findClass(env, "java/lang/Boolean"), "<init>", "(Z)V"),
			getJboolean(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsByte
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsByte
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	uint8 ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetValueAsByte(getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Short"),
			env->GetMethodID(findClass(env, "java/lang/Short"), "<init>", "(S)V"),
			getJshort(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsFloat
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsFloat
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	float ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetValueAsFloat(getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Float"),
			env->GetMethodID(findClass(env, "java/lang/Float"), "<init>", "(F)V"),
			getJfloat(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsInt
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsInt
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	int32 ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetValueAsInt(getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Integer"),
			env->GetMethodID(findClass(env, "java/lang/Integer"), "<init>", "(I)V"),
			getJint(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsShort
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsShort
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	int16 ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetValueAsShort(getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Short"),
			env->GetMethodID(findClass(env, "java/lang/Short"), "<init>", "(S)V"),
			getJshort(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsString
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsString
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	std::string ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetValueAsString(getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewStringUTF(ozwValue.c_str())
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsRaw
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsRaw
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	uint8 * ozwValue;
	uint8 length;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetValueAsRaw(getOzwValueId(env, valueId), &ozwValue, &length));

	jshortArray valueArray = env->NewShortArray(getJsize(length));
	jshort * valueElements = env->GetShortArrayElements(valueArray, NULL);
	for (uint8 i = 0; i < length; ++i)
	{
	    valueElements[i] = getJshort(ozwValue[i]);
	}
	env->ReleaseShortArrayElements(valueArray, valueElements, 0);

	delete [] ozwValue;

	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		valueArray
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueListSelectionString
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueListSelectionString
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	std::string ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetValueListSelection(getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewStringUTF(ozwValue.c_str())
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueListSelectionInt
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueListSelectionInt
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	int32 ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetValueListSelection(getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Integer"),
			env->GetMethodID(findClass(env, "java/lang/Integer"), "<init>", "(I)V"),
			getJint(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueListItems
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/List;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueListItems
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	std::vector<std::string> ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetValueListItems(getOzwValueId(env, valueId), &ozwValue));

    jmethodID addMethodId = env->GetMethodID(findClass(env, "java/util/List"), "add", "(Ljava/lang/Object;)Z");
    for(std::vector<std::string>::iterator it = ozwValue.begin(); it != ozwValue.end(); ++it)
    {
        env->CallBooleanMethod(
                value,
                addMethodId,
                env->NewStringUTF(it->c_str())
        );
    }

	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueFloatPrecision
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueFloatPrecision
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	uint8 ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->GetValueFloatPrecision(getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Short"),
			env->GetMethodID(findClass(env, "java/lang/Short"), "<init>", "(S)V"),
			getJshort(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsBool
 * Signature: (Lorg/zwave4j/ValueId;Z)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsBool
  (JNIEnv * env, jobject object, jobject valueId, jboolean value)
{
	return getJboolean(OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), getBool(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsByte
 * Signature: (Lorg/zwave4j/ValueId;S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsByte
  (JNIEnv * env, jobject object, jobject valueId, jshort value)
{
	return getJboolean(OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), getUint8(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsFloat
 * Signature: (Lorg/zwave4j/ValueId;F)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsFloat
  (JNIEnv * env, jobject object, jobject valueId, jfloat value)
{
	return getJboolean(OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), getFloat32(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsInt
 * Signature: (Lorg/zwave4j/ValueId;I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsInt
  (JNIEnv * env, jobject object, jobject valueId, jint value)
{
	return getJboolean(OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), getInt32(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsShort
 * Signature: (Lorg/zwave4j/ValueId;S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsShort
  (JNIEnv * env, jobject object, jobject valueId, jshort value)
{
	return getJboolean(OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), getInt16(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsRaw
 * Signature: (Lorg/zwave4j/ValueId;[S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsRaw
  (JNIEnv * env, jobject object, jobject valueId, jshortArray value)
{
	uint8 length = getUint8(env->GetArrayLength(value));
	uint8 * ozwValue = new uint8[length];

	jshort * valueElements = env->GetShortArrayElements(value, NULL);
	for (uint8 i = 0; i < length; ++i)
	{
	    ozwValue[i] = getUint8(valueElements[i]);
	}
	env->ReleaseShortArrayElements(value, valueElements, 0);

	return getJboolean(OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), ozwValue, length));
	delete [] ozwValue;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsString
 * Signature: (Lorg/zwave4j/ValueId;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsString
  (JNIEnv * env, jobject object, jobject valueId, jstring value)
{
	const char * valueChars = env->GetStringUTFChars(value, NULL); 
	jboolean result = getJboolean(OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), std::string(valueChars)));
	env->ReleaseStringUTFChars(value, valueChars);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueListSelection
 * Signature: (Lorg/zwave4j/ValueId;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueListSelection
  (JNIEnv * env, jobject object, jobject valueId, jstring selectedItem)
{
	const char * selectedItemChars = env->GetStringUTFChars(selectedItem, NULL); 
	jboolean result = getJboolean(OpenZWave::Manager::Get()->SetValueListSelection(getOzwValueId(env, valueId), std::string(selectedItemChars)));
	env->ReleaseStringUTFChars(selectedItem, selectedItemChars);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    refreshValue
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_refreshValue
  (JNIEnv * env, jobject object, jobject valueId)
{
	return getJboolean(OpenZWave::Manager::Get()->RefreshValue(getOzwValueId(env, valueId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setChangeVerified
 * Signature: (Lorg/zwave4j/ValueId;Z)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setChangeVerified
  (JNIEnv * env, jobject object, jobject valueId, jboolean verify)
{
	OpenZWave::Manager::Get()->SetChangeVerified(getOzwValueId(env, valueId), getBool(verify));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    pressButton
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_pressButton
  (JNIEnv * env, jobject object, jobject valueId)
{
	return getJboolean(OpenZWave::Manager::Get()->PressButton(getOzwValueId(env, valueId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    releaseButton
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_releaseButton
  (JNIEnv * env, jobject object, jobject valueId)
{
	return getJboolean(OpenZWave::Manager::Get()->ReleaseButton(getOzwValueId(env, valueId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNumSwitchPoints
 * Signature: (Lorg/zwave4j/ValueId;)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNumSwitchPoints
  (JNIEnv * env, jobject object, jobject id)
{
    return getJshort(OpenZWave::Manager::Get()->GetNumSwitchPoints(getOzwValueId(env, id)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setSwitchPoint
 * Signature: (Lorg/zwave4j/ValueId;SSB)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setSwitchPoint
  (JNIEnv * env, jobject object, jobject id, jshort hours, jshort minutes, jbyte setback)
{
    return getJboolean(OpenZWave::Manager::Get()->SetSwitchPoint(getOzwValueId(env, id), getUint8(hours), getUint8(minutes), getInt8(setback)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    removeSwitchPoint
 * Signature: (Lorg/zwave4j/ValueId;SS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_removeSwitchPoint
  (JNIEnv * env, jobject object, jobject id, jshort hours, jshort minutes)
{
    return getJboolean(OpenZWave::Manager::Get()->RemoveSwitchPoint(getOzwValueId(env, id), getUint8(hours), getUint8(minutes)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    clearSwitchPoints
 * Signature: (Lorg/zwave4j/ValueId;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_clearSwitchPoints
  (JNIEnv * env, jobject object, jobject id)
{
    OpenZWave::Manager::Get()->ClearSwitchPoints(getOzwValueId(env, id));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getSwitchPoint
 * Signature: (Lorg/zwave4j/ValueId;SLjava/util/concurrent/atomic/AtomicReference;Ljava/util/concurrent/atomic/AtomicReference;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getSwitchPoint
  (JNIEnv * env, jobject object, jobject id, jshort idx, jobject hours, jobject minutes, jobject setback)
{
    uint8 ozwHours, ozwMinutes;
    int8 ozwSetback;
    jboolean result = getJboolean(OpenZWave::Manager::Get()->GetSwitchPoint(getOzwValueId(env, id), getUint8(idx), &ozwHours, &ozwMinutes, &ozwSetback));

    env->CallVoidMethod(
		hours,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Short"),
			env->GetMethodID(findClass(env, "java/lang/Short"), "<init>", "(S)V"),
			getJshort(ozwHours)
		)
	);

	env->CallVoidMethod(
		minutes,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Short"),
			env->GetMethodID(findClass(env, "java/lang/Short"), "<init>", "(S)V"),
			getJshort(ozwMinutes)
		)
	);

	env->CallVoidMethod(
		setback,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Byte"),
			env->GetMethodID(findClass(env, "java/lang/Byte"), "<init>", "(B)V"),
			getJbyte(ozwSetback)
		)
	);

	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    switchAllOn
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_switchAllOn
  (JNIEnv * env, jobject object, jlong homeId)
{
	OpenZWave::Manager::Get()->SwitchAllOn(getUint32(homeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    switchAllOff
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_switchAllOff
  (JNIEnv * env, jobject object, jlong homeId)
{
	OpenZWave::Manager::Get()->SwitchAllOff(getUint32(homeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setConfigParam
 * Signature: (JSSIS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setConfigParam__JSSIS
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort param, jint value, jshort size)
{
	return getJboolean(OpenZWave::Manager::Get()->SetConfigParam(getUint32(homeId), getUint8(nodeId), getUint8(param), getInt32(value), getUint8(size)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setConfigParam
 * Signature: (JSSI)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setConfigParam__JSSI
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort param, jint value)
{
    return getJboolean(OpenZWave::Manager::Get()->SetConfigParam(getUint32(homeId), getUint8(nodeId), getUint8(param), getInt32(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    requestConfigParam
 * Signature: (JSS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_requestConfigParam
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort param)
{
	OpenZWave::Manager::Get()->RequestConfigParam(getUint32(homeId), getUint8(nodeId), getUint8(param));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    requestAllConfigParams
 * Signature: (JS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_requestAllConfigParams
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	OpenZWave::Manager::Get()->RequestAllConfigParams(getUint32(homeId), getUint8(nodeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNumGroups
 * Signature: (JS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNumGroups
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
    return getJshort(OpenZWave::Manager::Get()->GetNumGroups(getUint32(homeId), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getAssociations
 * Signature: (JSSLjava/util/concurrent/atomic/AtomicReference;)J
 */
JNIEXPORT jlong JNICALL Java_org_zwave4j_Manager_getAssociations
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort groupIdx, jobject associations)
{
    uint8 * ozwAssociations;

    jlong associationsAmount = getJlong(OpenZWave::Manager::Get()->GetAssociations(getUint32(homeId), getUint8(nodeId), getUint8(groupIdx), &ozwAssociations));

    jshortArray associationsArray = env->NewShortArray(getJsize(associationsAmount));
	jshort * neighborsArrayElements = env->GetShortArrayElements(associationsArray, NULL);
	for (uint32 i = 0; i < associationsAmount; ++i)
	{
	    neighborsArrayElements[i] = getJshort(ozwAssociations[i]);
	}
	env->ReleaseShortArrayElements(associationsArray, neighborsArrayElements, 0);

	delete [] ozwAssociations;

	env->CallVoidMethod(
		associations,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		associationsArray
	);

	return associationsAmount;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getAssociationsWithInstance
 * Signature: (JSSLjava/util/concurrent/atomic/AtomicReference;)J
 */
JNIEXPORT jlong JNICALL Java_org_zwave4j_Manager_getAssociationsWithInstance
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort groupIdx, jobject associations)
{
    OpenZWave::InstanceAssociation * ozwAssociations;

    jlong associationsAmount = getJlong(OpenZWave::Manager::Get()->GetAssociations(getUint32(homeId), getUint8(nodeId), getUint8(groupIdx), &ozwAssociations));

    jclass associationClass = findClass(env, "org/zwave4j/InstanceAssociation");

    jobjectArray associationsArray = env->NewObjectArray(getJsize(associationsAmount), associationClass, NULL);
	for (uint32 i = 0; i < associationsAmount; ++i)
	{
	    jobject association = env->NewObject(associationClass,
	  	env->GetMethodID(associationClass, "<init>", "(SS)V"),
		getJshort(ozwAssociations[i].m_nodeId),
		getJshort(ozwAssociations[i].m_instance));
	    env->SetObjectArrayElement(associationsArray, getJsize(i), association);
	}

	delete [] ozwAssociations;

	env->CallVoidMethod(
		associations,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		associationsArray
	);

	return associationsAmount;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getMaxAssociations
 * Signature: (JSS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getMaxAssociations
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort groupIdx)
{
    return getJshort(OpenZWave::Manager::Get()->GetMaxAssociations(getUint32(homeId), getUint8(nodeId), getUint8(groupIdx)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getGroupLabel
 * Signature: (JSS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getGroupLabel
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort groupIdx)
{
    return env->NewStringUTF(OpenZWave::Manager::Get()->GetGroupLabel(getUint32(homeId), getUint8(nodeId), getUint8(groupIdx)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addAssociation
 * Signature: (JSSSS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_addAssociation
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort groupIdx, jshort targetNodeId, jshort instance)
{
    OpenZWave::Manager::Get()->AddAssociation(getUint32(homeId), getUint8(nodeId), getUint8(groupIdx), getUint8(targetNodeId), getUint8(instance));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    removeAssociation
 * Signature: (JSSSS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_removeAssociation
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort groupIdx, jshort targetNodeId, jshort instance)
{
    OpenZWave::Manager::Get()->RemoveAssociation(getUint32(homeId), getUint8(nodeId), getUint8(groupIdx), getUint8(targetNodeId), getUint8(instance));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addWatcher
 * Signature: (Lorg/zwave4j/NotificationWatcher;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_addWatcher
  (JNIEnv * env, jobject object, jobject notificationWatcher, jobject context)
{
    std::pair<jobject, jobject> * pair = new std::pair<jobject, jobject>(
        env->NewGlobalRef(notificationWatcher),
        env->NewGlobalRef(context)
    );
	
	// This key is deallocated after this scope closes causing numerous issues.
	//notificationWatchers[std::pair<jobject, jobject>(notificationWatcher, context)] = pair;

	notificationWatchers[*pair] = pair;
	
    OpenZWave::Manager::Get()->AddWatcher(onNotification, pair);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    removeWatcher
 * Signature: (Lorg/zwave4j/NotificationWatcher;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_removeWatcher
  (JNIEnv * env, jobject object, jobject notificationWatcher, jobject context)
{
    std::pair<jobject, jobject> * pair = notificationWatchers[std::pair<jobject, jobject>(notificationWatcher, context)];
	notificationWatchers.erase(std::pair<jobject, jobject>(notificationWatcher, context));
	
	if (pair->first != NULL)
		env->DeleteGlobalRef(pair->first);
	
	if (pair->second != NULL)
		env->DeleteGlobalRef(pair->second);

	OpenZWave::Manager::Get()->RemoveWatcher(onNotification, pair);
    delete pair;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    resetController
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_resetController
  (JNIEnv * env, jobject object, jlong homeId)
{
    OpenZWave::Manager::Get()->ResetController(getUint32(homeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    softReset
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_softReset
  (JNIEnv * env, jobject object, jlong homeId)
{
    OpenZWave::Manager::Get()->SoftReset(getUint32(homeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    beginControllerCommand
 * Signature: (JLorg/zwave4j/ControllerCommand;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_beginControllerCommand__JLorg_zwave4j_ControllerCommand_2
  (JNIEnv * env, jobject object, jlong homeId, jobject command)
{
    return getJboolean(OpenZWave::Manager::Get()->BeginControllerCommand(getUint32(homeId), getOzwControllerCommand(env, command)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    beginControllerCommand
 * Signature: (JLorg/zwave4j/ControllerCommand;Lorg/zwave4j/ControllerCallback;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_beginControllerCommand__JLorg_zwave4j_ControllerCommand_2Lorg_zwave4j_ControllerCallback_2
  (JNIEnv * env, jobject object, jlong homeId, jobject command, jobject callback)
{
    std::pair<jobject, jobject> * pair = new std::pair<jobject, jobject>(
        env->NewGlobalRef(callback),
        NULL
    );
    return getJboolean(OpenZWave::Manager::Get()->BeginControllerCommand(getUint32(homeId), getOzwControllerCommand(env, command), onControllerCallback, pair));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    beginControllerCommand
 * Signature: (JLorg/zwave4j/ControllerCommand;Lorg/zwave4j/ControllerCallback;Ljava/lang/Object;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_beginControllerCommand__JLorg_zwave4j_ControllerCommand_2Lorg_zwave4j_ControllerCallback_2Ljava_lang_Object_2
  (JNIEnv * env, jobject object, jlong homeId, jobject command, jobject callback, jobject context)
{
    std::pair<jobject, jobject> * pair = new std::pair<jobject, jobject>(
        env->NewGlobalRef(callback),
        env->NewGlobalRef(context)
    );
    return getJboolean(OpenZWave::Manager::Get()->BeginControllerCommand(getUint32(homeId), getOzwControllerCommand(env, command), onControllerCallback, pair));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    beginControllerCommand
 * Signature: (JLorg/zwave4j/ControllerCommand;Lorg/zwave4j/ControllerCallback;Ljava/lang/Object;Z)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_beginControllerCommand__JLorg_zwave4j_ControllerCommand_2Lorg_zwave4j_ControllerCallback_2Ljava_lang_Object_2Z
  (JNIEnv * env, jobject object, jlong homeId, jobject command, jobject callback, jobject context, jboolean highPower)
{
    std::pair<jobject, jobject> * pair = new std::pair<jobject, jobject>(
        env->NewGlobalRef(callback),
        env->NewGlobalRef(context)
    );
    return getJboolean(OpenZWave::Manager::Get()->BeginControllerCommand(getUint32(homeId), getOzwControllerCommand(env, command), onControllerCallback, pair, getBool(highPower)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    beginControllerCommand
 * Signature: (JLorg/zwave4j/ControllerCommand;Lorg/zwave4j/ControllerCallback;Ljava/lang/Object;ZS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_beginControllerCommand__JLorg_zwave4j_ControllerCommand_2Lorg_zwave4j_ControllerCallback_2Ljava_lang_Object_2ZS
  (JNIEnv * env, jobject object, jlong homeId, jobject command, jobject callback, jobject context, jboolean highPower, jshort nodeId)
{
    std::pair<jobject, jobject> * pair = new std::pair<jobject, jobject>(
        env->NewGlobalRef(callback),
        env->NewGlobalRef(context)
    );
    return getJboolean(OpenZWave::Manager::Get()->BeginControllerCommand(getUint32(homeId), getOzwControllerCommand(env, command), onControllerCallback, pair, getBool(highPower), getUint8(nodeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    beginControllerCommand
 * Signature: (JLorg/zwave4j/ControllerCommand;Lorg/zwave4j/ControllerCallback;Ljava/lang/Object;ZSS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_beginControllerCommand__JLorg_zwave4j_ControllerCommand_2Lorg_zwave4j_ControllerCallback_2Ljava_lang_Object_2ZSS
  (JNIEnv * env, jobject object, jlong homeId, jobject command, jobject callback, jobject context, jboolean highPower, jshort nodeId, jshort arg)
{
    std::pair<jobject, jobject> * pair = new std::pair<jobject, jobject>(
        env->NewGlobalRef(callback),
        env->NewGlobalRef(context)
    );
    return getJboolean(OpenZWave::Manager::Get()->BeginControllerCommand(getUint32(homeId), getOzwControllerCommand(env, command), onControllerCallback, pair, getBool(highPower), getUint8(nodeId), getUint8(arg)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    cancelControllerCommand
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_cancelControllerCommand
  (JNIEnv * env, jobject object, jlong homeId)
{
    return getJboolean(OpenZWave::Manager::Get()->CancelControllerCommand(getUint32(homeId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    testNetworkNode
 * Signature: (JSJ)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_testNetworkNode
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jlong count)
{
    OpenZWave::Manager::Get()->TestNetworkNode(getUint32(homeId), getUint8(nodeId), getUint32(count));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    testNetwork
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_testNetwork
  (JNIEnv * env, jobject object, jlong homeId, jlong count)
{
    OpenZWave::Manager::Get()->TestNetwork(getUint32(homeId), getUint32(count));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    healNetworkNode
 * Signature: (JSZ)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_healNetworkNode
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jboolean doRR)
{
    OpenZWave::Manager::Get()->HealNetworkNode(getUint32(homeId), getUint8(nodeId), getBool(doRR));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    healNetwork
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_healNetwork
  (JNIEnv * env, jobject object, jlong homeId, jboolean doRR)
{
    OpenZWave::Manager::Get()->HealNetwork(getUint32(homeId), getBool(doRR));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNumScenes
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNumScenes
  (JNIEnv * env, jobject object)
{
    return getJshort(OpenZWave::Manager::Get()->GetNumScenes());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getAllScenes
 * Signature: (Ljava/util/concurrent/atomic/AtomicReference;)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getAllScenes
  (JNIEnv * env, jobject object, jobject sceneIds)
{
    uint8 * ozwScenesIds;
    uint8 scenesIdsAmount = OpenZWave::Manager::Get()->GetAllScenes(&ozwScenesIds);

    jshortArray scenesIdsArray = env->NewShortArray(getJsize(scenesIdsAmount));
	jshort * neighborsArrayElements = env->GetShortArrayElements(scenesIdsArray, NULL);
	for (uint32 i = 0; i < scenesIdsAmount; ++i)
	{
	    neighborsArrayElements[i] = getJshort(ozwScenesIds[i]);
	}
	env->ReleaseShortArrayElements(scenesIdsArray, neighborsArrayElements, 0);

	delete [] ozwScenesIds;

	env->CallVoidMethod(
		sceneIds,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		scenesIdsArray
	);

	return scenesIdsAmount;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    removeAllScenes
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_removeAllScenes
  (JNIEnv * env, jobject object, jlong homeId)
{
    OpenZWave::Manager::Get()->RemoveAllScenes(getUint32(homeId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    createScene
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_createScene
  (JNIEnv * env, jobject object)
{
    return getJshort(OpenZWave::Manager::Get()->CreateScene());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    removeScene
 * Signature: (S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_removeScene
  (JNIEnv * env, jobject object, jshort sceneId)
{
    return getJboolean(OpenZWave::Manager::Get()->RemoveScene(getUint8(sceneId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addSceneValueAsBool
 * Signature: (SLorg/zwave4j/ValueId;Z)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_addSceneValueAsBool
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jboolean value)
{
    return getJboolean(OpenZWave::Manager::Get()->AddSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), getBool(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addSceneValueAsByte
 * Signature: (SLorg/zwave4j/ValueId;S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_addSceneValueAsByte
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jshort value)
{
    return getJboolean(OpenZWave::Manager::Get()->AddSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), getUint8(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addSceneValueAsFloat
 * Signature: (SLorg/zwave4j/ValueId;F)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_addSceneValueAsFloat
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jfloat value)
{
    return getJboolean(OpenZWave::Manager::Get()->AddSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), getFloat32(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addSceneValueAsInt
 * Signature: (SLorg/zwave4j/ValueId;I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_addSceneValueAsInt
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jint value)
{
    return getJboolean(OpenZWave::Manager::Get()->AddSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), getInt32(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addSceneValueAsShort
 * Signature: (SLorg/zwave4j/ValueId;S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_addSceneValueAsShort
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jshort value)
{
    return getJboolean(OpenZWave::Manager::Get()->AddSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), getInt16(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addSceneValueAsString
 * Signature: (SLorg/zwave4j/ValueId;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_addSceneValueAsString
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jstring value)
{
    const char * valueChars = env->GetStringUTFChars(value, NULL);

    jboolean result = getJboolean(OpenZWave::Manager::Get()->AddSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), std::string(valueChars)));

    env->ReleaseStringUTFChars(value, valueChars);
    return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addSceneValueListSelection
 * Signature: (SLorg/zwave4j/ValueId;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_addSceneValueListSelection__SLorg_zwave4j_ValueId_2Ljava_lang_String_2
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jstring value)
{
    const char * valueChars = env->GetStringUTFChars(value, NULL);

    jboolean result = getJboolean(OpenZWave::Manager::Get()->AddSceneValueListSelection(getUint8(sceneId), getOzwValueId(env, valueId), std::string(valueChars)));

    env->ReleaseStringUTFChars(value, valueChars);
    return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addSceneValueListSelection
 * Signature: (SLorg/zwave4j/ValueId;I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_addSceneValueListSelection__SLorg_zwave4j_ValueId_2I
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jint value)
{
    return getJboolean(OpenZWave::Manager::Get()->AddSceneValueListSelection(getUint8(sceneId), getOzwValueId(env, valueId), getInt32(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    removeSceneValue
 * Signature: (SLorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_removeSceneValue
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId)
{
    return getJboolean(OpenZWave::Manager::Get()->RemoveSceneValue(getUint8(sceneId), getOzwValueId(env, valueId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    sceneGetValues
 * Signature: (SLjava/util/List;)I
 */
JNIEXPORT jint JNICALL Java_org_zwave4j_Manager_sceneGetValues
  (JNIEnv * env, jobject object, jshort sceneId, jobject value)
{
    std::vector<OpenZWave::ValueID> ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->SceneGetValues(getUint8(sceneId), &ozwValue));

    jmethodID addMethodId = env->GetMethodID(findClass(env, "java/util/List"), "add", "(Ljava/lang/Object;)Z");
    for(std::vector<OpenZWave::ValueID>::iterator it = ozwValue.begin(); it != ozwValue.end(); ++it)
    {
        env->CallBooleanMethod(
                value,
                addMethodId,
                getValueId(env, &*it)
        );
    }

	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    sceneGetValueAsBool
 * Signature: (SLorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_sceneGetValueAsBool
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jobject value)
{
    bool ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->SceneGetValueAsBool(getJshort(sceneId), getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Boolean"),
			env->GetMethodID(findClass(env, "java/lang/Boolean"), "<init>", "(Z)V"),
			getJboolean(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    sceneGetValueAsByte
 * Signature: (SLorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_sceneGetValueAsByte
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jobject value)
{
    uint8 ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->SceneGetValueAsByte(getJshort(sceneId), getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Short"),
			env->GetMethodID(findClass(env, "java/lang/Short"), "<init>", "(S)V"),
			getJshort(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    sceneGetValueAsFloat
 * Signature: (SLorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_sceneGetValueAsFloat
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jobject value)
{
    float ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->SceneGetValueAsFloat(getJshort(sceneId), getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Float"),
			env->GetMethodID(findClass(env, "java/lang/Float"), "<init>", "(F)V"),
			getJfloat(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    sceneGetValueAsInt
 * Signature: (SLorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_sceneGetValueAsInt
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jobject value)
{
    int32 ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->SceneGetValueAsInt(getJshort(sceneId), getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Integer"),
			env->GetMethodID(findClass(env, "java/lang/Integer"), "<init>", "(I)V"),
			getJint(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    sceneGetValueAsShort
 * Signature: (SLorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_sceneGetValueAsShort
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jobject value)
{
	int16 ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->SceneGetValueAsShort(getJshort(sceneId), getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Short"),
			env->GetMethodID(findClass(env, "java/lang/Short"), "<init>", "(S)V"),
			getJshort(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    sceneGetValueAsString
 * Signature: (SLorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_sceneGetValueAsString
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jobject value)
{
    std::string ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->SceneGetValueAsString(getJshort(sceneId), getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewStringUTF(ozwValue.c_str())
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    sceneGetValueListSelectionString
 * Signature: (SLorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_sceneGetValueListSelectionString
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jobject value)
{
    std::string ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->SceneGetValueListSelection(getJshort(sceneId), getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewStringUTF(ozwValue.c_str())
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    sceneGetValueListSelectionInt
 * Signature: (SLorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_sceneGetValueListSelectionInt
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jobject value)
{
	int32 ozwValue;
	jboolean result = getJboolean(OpenZWave::Manager::Get()->SceneGetValueListSelection(getJshort(sceneId), getOzwValueId(env, valueId), &ozwValue));
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Integer"),
			env->GetMethodID(findClass(env, "java/lang/Integer"), "<init>", "(I)V"),
			getJint(ozwValue)
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setSceneValueAsBool
 * Signature: (SLorg/zwave4j/ValueId;Z)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setSceneValueAsBool
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jboolean value)
{
    return getJboolean(OpenZWave::Manager::Get()->SetSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), getBool(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setSceneValueAsByte
 * Signature: (SLorg/zwave4j/ValueId;S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setSceneValueAsByte
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jshort value)
{
    return getJboolean(OpenZWave::Manager::Get()->SetSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), getUint8(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setSceneValueAsFloat
 * Signature: (SLorg/zwave4j/ValueId;F)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setSceneValueAsFloat
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jfloat value)
{
    return getJboolean(OpenZWave::Manager::Get()->SetSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), getFloat32(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setSceneValueAsInt
 * Signature: (SLorg/zwave4j/ValueId;I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setSceneValueAsInt
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jint value)
{
    return getJboolean(OpenZWave::Manager::Get()->SetSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), getInt32(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setSceneValueAsShort
 * Signature: (SLorg/zwave4j/ValueId;S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setSceneValueAsShort
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jshort value)
{
    return getJboolean(OpenZWave::Manager::Get()->SetSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), getInt16(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setSceneValueAsString
 * Signature: (SLorg/zwave4j/ValueId;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setSceneValueAsString
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jstring value)
{
    const char * valueChars = env->GetStringUTFChars(value, NULL);

    jboolean result = getJboolean(OpenZWave::Manager::Get()->SetSceneValue(getUint8(sceneId), getOzwValueId(env, valueId), std::string(valueChars)));

    env->ReleaseStringUTFChars(value, valueChars);
    return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setSceneValueListSelection
 * Signature: (SLorg/zwave4j/ValueId;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setSceneValueListSelection__SLorg_zwave4j_ValueId_2Ljava_lang_String_2
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jstring value)
{
    const char * valueChars = env->GetStringUTFChars(value, NULL);

    jboolean result = getJboolean(OpenZWave::Manager::Get()->SetSceneValueListSelection(getUint8(sceneId), getOzwValueId(env, valueId), std::string(valueChars)));

    env->ReleaseStringUTFChars(value, valueChars);
    return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setSceneValueListSelection
 * Signature: (SLorg/zwave4j/ValueId;I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setSceneValueListSelection__SLorg_zwave4j_ValueId_2I
  (JNIEnv * env, jobject object, jshort sceneId, jobject valueId, jint value)
{
    return getJboolean(OpenZWave::Manager::Get()->SetSceneValueListSelection(getUint8(sceneId), getOzwValueId(env, valueId), getInt32(value)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getSceneLabel
 * Signature: (S)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getSceneLabel
  (JNIEnv * env, jobject object, jshort sceneId)
{
   return env->NewStringUTF(OpenZWave::Manager::Get()->GetSceneLabel(getUint8(sceneId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setSceneLabel
 * Signature: (SLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setSceneLabel
  (JNIEnv * env, jobject object, jshort sceneId, jstring value)
{
    const char * valueChars = env->GetStringUTFChars(value, NULL);

    OpenZWave::Manager::Get()->SetSceneLabel(getUint8(sceneId), std::string(valueChars));

    env->ReleaseStringUTFChars(value, valueChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    sceneExists
 * Signature: (S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_sceneExists
  (JNIEnv * env, jobject object, jshort sceneId)
{
    return getJboolean(OpenZWave::Manager::Get()->SceneExists(getUint8(sceneId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    activateScene
 * Signature: (S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_activateScene
  (JNIEnv * env, jobject object, jshort sceneId)
{
    return getJboolean(OpenZWave::Manager::Get()->ActivateScene(getUint8(sceneId)));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getDriverStatistics
 * Signature: (JLorg/zwave4j/DriverData;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_getDriverStatistics
  (JNIEnv * env, jobject object, jlong homeId, jobject data)
{
    jclass clazz = findClass(env, "org/zwave4j/DriverData");
    OpenZWave::Driver::DriverData ozwDriverData = OpenZWave::Driver::DriverData();
    ozwDriverData.m_SOFCnt = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getSofCnt", "()J")));
    ozwDriverData.m_ACKWaiting = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getAckWaiting", "()J")));
    ozwDriverData.m_readAborts = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getReadAborts", "()J")));
    ozwDriverData.m_badChecksum = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getBadChecksum", "()J")));			
    ozwDriverData.m_readCnt = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getReadCnt", "()J")));			
    ozwDriverData.m_writeCnt = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getWriteCnt", "()J")));			
    ozwDriverData.m_CANCnt = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getCanCnt", "()J")));			
    ozwDriverData.m_NAKCnt = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getNakCnt", "()J")));			
    ozwDriverData.m_ACKCnt = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getAckCnt", "()J")));			
    ozwDriverData.m_OOFCnt = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getOofCnt", "()J")));			
    ozwDriverData.m_dropped = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getDropped", "()J")));			
    ozwDriverData.m_retries = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getRetries", "()J")));			
    ozwDriverData.m_callbacks = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getCallbacks", "()J")));			
    ozwDriverData.m_badroutes = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getBadRoutes", "()J")));			
    ozwDriverData.m_noack = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getNoAck", "()J")));				
    ozwDriverData.m_netbusy = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getNetBusy", "()J")));			
    ozwDriverData.m_notidle = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getNotIdle", "()J")));
    ozwDriverData.m_nondelivery = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getNondelivery", "()J")));			
    ozwDriverData.m_routedbusy = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getRoutedBusy", "()J")));			
    ozwDriverData.m_broadcastReadCnt = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getBroadcastReadCnt", "()J")));		
    ozwDriverData.m_broadcastWriteCnt = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getBroadcastWriteCnt", "()J")));		
    
    OpenZWave::Manager::Get()->GetDriverStatistics(getUint32(homeId), &ozwDriverData);
    
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setSofCnt", "(J)V"), getJlong(ozwDriverData.m_SOFCnt));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setAckWaiting", "(J)V"), getJlong(ozwDriverData.m_ACKWaiting));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setReadAborts", "(J)V"), getJlong(ozwDriverData.m_readAborts));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setBadChecksum", "(J)V"), getJlong(ozwDriverData.m_badChecksum));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setReadCnt", "(J)V"), getJlong(ozwDriverData.m_readCnt));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setWriteCnt", "(J)V"), getJlong(ozwDriverData.m_writeCnt));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setCanCnt", "(J)V"), getJlong(ozwDriverData.m_CANCnt));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setNakCnt", "(J)V"), getJlong(ozwDriverData.m_NAKCnt));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setAckCnt", "(J)V"), getJlong(ozwDriverData.m_ACKCnt));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setOofCnt", "(J)V"), getJlong(ozwDriverData.m_OOFCnt));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setDropped", "(J)V"), getJlong(ozwDriverData.m_dropped));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setRetries", "(J)V"), getJlong(ozwDriverData.m_retries));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setCallbacks", "(J)V"), getJlong(ozwDriverData.m_callbacks));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setBadRoutes", "(J)V"), getJlong(ozwDriverData.m_badroutes));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setNoAck", "(J)V"), getJlong(ozwDriverData.m_noack));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setNetBusy", "(J)V"), getJlong(ozwDriverData.m_netbusy));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setNotIdle", "(J)V"), getJlong(ozwDriverData.m_notidle));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setNondelivery", "(J)V"), getJlong(ozwDriverData.m_nondelivery));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setRoutedBusy", "(J)V"), getJlong(ozwDriverData.m_routedbusy));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setBroadcastReadCnt", "(J)V"), getJlong(ozwDriverData.m_broadcastReadCnt));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setBroadcastWriteCnt", "(J)V"), getJlong(ozwDriverData.m_broadcastWriteCnt));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeStatistics
 * Signature: (JSLorg/zwave4j/NodeData;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_getNodeStatistics
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jobject data)
{
    jclass clazz = findClass(env, "org/zwave4j/NodeData");
    OpenZWave::Node::NodeData ozwNodeData;
    ozwNodeData.m_sentCnt = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getSentCnt", "()J")));
    ozwNodeData.m_sentFailed = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getSentFailed", "()J")));
    ozwNodeData.m_retries = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getRetries", "()J")));
    ozwNodeData.m_receivedCnt = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getReceivedCnt", "()J")));
    ozwNodeData.m_receivedDups = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getReceivedDups", "()J")));
    ozwNodeData.m_receivedUnsolicited = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getReceivedUnsolicited", "()J")));

    jstring sentTs = (jstring) env->CallObjectMethod(data, env->GetMethodID(clazz, "getSentTs", "()Ljava/lang/String;"));
    const char * sentTsChars = NULL;
    if (sentTs != NULL) {
        const char * sentTsChars = env->GetStringUTFChars(sentTs, NULL);
        ozwNodeData.m_sentTS = std::string(sentTsChars);
    }

    jstring receivedTs = (jstring) env->CallObjectMethod(data, env->GetMethodID(clazz, "getReceivedTs", "()Ljava/lang/String;"));
    const char * receivedTsChars = NULL;
    if (receivedTs != NULL) {
        const char * receivedTsChars = env->GetStringUTFChars(receivedTs, NULL);
        ozwNodeData.m_receivedTS = std::string(receivedTsChars);
    }

    ozwNodeData.m_lastRequestRTT = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getLastRequestRtt", "()J")));
    ozwNodeData.m_averageRequestRTT = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getAverageRequestRtt", "()J")));
    ozwNodeData.m_lastResponseRTT = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getLastResponseRtt", "()J")));
    ozwNodeData.m_averageResponseRTT = getUint32(env->CallLongMethod(data, env->GetMethodID(clazz, "getAverageResponseRtt", "()J")));
    ozwNodeData.m_quality = getUint8(env->CallShortMethod(data, env->GetMethodID(clazz, "getQuality", "()S")));

    jshortArray lastReceivedMessage = (jshortArray) env->CallObjectMethod(data, env->GetMethodID(clazz, "getLastReceivedMessage", "()[S"));
    jshort * lastReceivedMessageElements = env->GetShortArrayElements(lastReceivedMessage, NULL);
    for (uint32 i = 0; i < 254; ++i)
    {
        ozwNodeData.m_lastReceivedMessage[i] = getUint8(lastReceivedMessageElements[i]);
    }
    env->ReleaseShortArrayElements(lastReceivedMessage, lastReceivedMessageElements, 0);

    jobject ccData = env->CallObjectMethod(data, env->GetMethodID(clazz, "getCcData", "()Ljava/util/List;"));
    jint ccDataSize = env->CallIntMethod(ccData, env->GetMethodID(findClass(env, "java/util/List"), "size", "()I"));
    ozwNodeData.m_ccData.resize(ccDataSize);
    for (std::list<OpenZWave::Node::CommandClassData>::iterator it = ozwNodeData.m_ccData.begin(); it != ozwNodeData.m_ccData.end(); it++) {
        (*it) = getOzwCommandClassData(env, env->CallObjectMethod(ccData, env->GetMethodID(findClass(env, "java/util/List"), "get", "()Ljava/lang/Object;")));
    }

    OpenZWave::Manager::Get()->GetNodeStatistics(getUint32(homeId), getUint8(nodeId), &ozwNodeData);

    if (sentTsChars != NULL) {
        env->ReleaseStringUTFChars(sentTs, sentTsChars);
    }
    if (receivedTsChars != NULL) {
        env->ReleaseStringUTFChars(receivedTs, receivedTsChars);
    }

    env->CallVoidMethod(data, env->GetMethodID(clazz, "setSentCnt", "(J)V"), getJlong(ozwNodeData.m_sentCnt));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setSentFailed", "(J)V"), getJlong(ozwNodeData.m_sentFailed));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setRetries", "(J)V"), getJlong(ozwNodeData.m_retries));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setReceivedCnt", "(J)V"), getJlong(ozwNodeData.m_receivedCnt));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setReceivedDups", "(J)V"), getJlong(ozwNodeData.m_receivedDups));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setReceivedUnsolicited", "(J)V"), getJlong(ozwNodeData.m_receivedUnsolicited));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setSentTs", "(Ljava/lang/String;)V"), env->NewStringUTF(ozwNodeData.m_sentTS.c_str()));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setReceivedTs", "(Ljava/lang/String;)V"), env->NewStringUTF(ozwNodeData.m_receivedTS.c_str()));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setLastRequestRtt", "(J)V"), getJlong(ozwNodeData.m_lastRequestRTT));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setAverageRequestRtt", "(J)V"), getJlong(ozwNodeData.m_averageRequestRTT));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setLastResponseRtt", "(J)V"), getJlong(ozwNodeData.m_lastResponseRTT));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setAverageResponseRtt", "(J)V"), getJlong(ozwNodeData.m_averageResponseRTT));
    env->CallVoidMethod(data, env->GetMethodID(clazz, "setQuality", "(S)V"), getJshort(ozwNodeData.m_quality));

    lastReceivedMessage = (jshortArray) env->CallObjectMethod(data, env->GetMethodID(clazz, "getLastReceivedMessage", "()[S"));
	lastReceivedMessageElements = env->GetShortArrayElements(lastReceivedMessage, NULL);
	for (uint32 i = 0; i < 254; ++i)
	{
	    lastReceivedMessageElements[i] = getJshort(ozwNodeData.m_lastReceivedMessage[i]);
	}
	env->ReleaseShortArrayElements(lastReceivedMessage, lastReceivedMessageElements, 0);

    ccData = env->CallObjectMethod(data, env->GetMethodID(clazz, "getCcData", "()Ljava/util/List;"));
    env->CallVoidMethod(ccData, env->GetMethodID(findClass(env, "java/util/List"), "clear", "()V"));
    for (std::list<OpenZWave::Node::CommandClassData>::iterator it = ozwNodeData.m_ccData.begin(); it != ozwNodeData.m_ccData.end(); it++) {
        env->CallVoidMethod(
            ccData,
            env->GetMethodID(findClass(env, "java/util/List"), "add", "(Ljava/lang/Object;)Z"),
            getCommandClassData(env, &*it)
        );
    }
}
