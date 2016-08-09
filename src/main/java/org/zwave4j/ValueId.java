package org.zwave4j;

import java.io.Serializable;

/**
 * @author zagumennikov
 */
public class ValueId implements Serializable {

    private long homeId;
    private short nodeId;
    private ValueGenre genre;
    private short commandClassId;
    private short instance;
    private short index;
    private ValueType type;

    public ValueId(long homeId, short nodeId, ValueGenre genre, short commandClassId, short instance, short index, ValueType type) {
        this.homeId = homeId;
        this.nodeId = nodeId;
        this.genre = genre;
        this.commandClassId = commandClassId;
        this.instance = instance;
        this.index = index;
        this.type = type;
    }

    public long getHomeId() {
        return homeId;
    }

    public short getNodeId() {
        return nodeId;
    }

    public ValueGenre getGenre() {
        return genre;
    }

    public short getCommandClassId() {
        return commandClassId;
    }

    public short getInstance() {
        return instance;
    }

    public short getIndex() {
        return index;
    }

    public ValueType getType(){
        return type;
    }
}
