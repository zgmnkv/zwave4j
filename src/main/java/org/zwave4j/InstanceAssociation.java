package org.zwave4j;

import java.io.Serializable;

/**
 * @author TEK
 */
public class InstanceAssociation implements Serializable {

    private short nodeId;
    private short instance;

    public InstanceAssociation(short nodeId, short instance) {
        this.nodeId = nodeId;
        this.instance = instance;
    }

    public short getNodeId() {
        return nodeId;
    }

    public long getInstance() {
        return instance;
    }
}
