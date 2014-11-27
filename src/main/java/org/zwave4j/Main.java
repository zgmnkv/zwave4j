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

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.concurrent.atomic.AtomicReference;

/**
 * @author zagumennikov
 */
public class Main {

    private static long homeId;
    private static boolean ready = false;

    public static void main(String[] args) throws IOException {
        NativeLibraryLoader.loadLibrary(ZWave4j.LIBRARY_NAME, ZWave4j.class);

        final Options options = Options.create(args[0], "", "");
        options.addOptionBool("ConsoleOutput", false);
        options.lock();

        final Manager manager = Manager.create();

        final NotificationWatcher watcher = new NotificationWatcher() {
            @Override
            public void onNotification(Notification notification, Object context) {
                switch (notification.getType()) {
                    case DRIVER_READY:
                        System.out.println(String.format("Driver ready\n" +
                                "\thome id: %d",
                                notification.getHomeId()
                        ));
                        homeId = notification.getHomeId();
                        break;
                    case DRIVER_FAILED:
                        System.out.println("Driver failed");
                        break;
                    case DRIVER_RESET:
                        System.out.println("Driver reset");
                        break;
                    case DRIVER_REMOVED:
                        System.out.println("Driver removed");
                        break;
                    case AWAKE_NODES_QUERIED:
                        System.out.println("Awake nodes queried");
                        break;
                    case ALL_NODES_QUERIED:
                        System.out.println("All nodes queried");
                        manager.writeConfig(homeId);
                        ready = true;
                        break;
                    case ALL_NODES_QUERIED_SOME_DEAD:
                        System.out.println("All nodes queried some dead");
                        manager.writeConfig(homeId);
                        ready = true;
                        break;
                    case POLLING_ENABLED:
                        System.out.println("Polling enabled");
                        break;
                    case POLLING_DISABLED:
                        System.out.println("Polling disabled");
                        break;
                    case NODE_NEW:
                        System.out.println(String.format("Node new\n" +
                                "\tnode id: %d",
                                notification.getNodeId()
                        ));
                        break;
                    case NODE_ADDED:
                        System.out.println(String.format("Node added\n" +
                                "\tnode id: %d",
                                notification.getNodeId()
                        ));
                        break;
                    case NODE_REMOVED:
                        System.out.println(String.format("Node removed\n" +
                                "\tnode id: %d",
                                notification.getNodeId()
                        ));
                        break;
                    case ESSENTIAL_NODE_QUERIES_COMPLETE:
                        System.out.println(String.format("Node essential queries complete\n" +
                                "\tnode id: %d",
                                notification.getNodeId()
                        ));
                        break;
                    case NODE_QUERIES_COMPLETE:
                        System.out.println(String.format("Node queries complete\n" +
                                "\tnode id: %d",
                                notification.getNodeId()
                        ));
                        break;
                    case NODE_EVENT:
                        System.out.println(String.format("Node event\n" +
                                "\tnode id: %d\n" +
                                "\tevent id: %d",
                                notification.getNodeId(),
                                notification.getEvent()
                        ));
                        break;
                    case NODE_NAMING:
                        System.out.println(String.format("Node naming\n" +
                                "\tnode id: %d",
                                notification.getNodeId()
                        ));
                        break;
                    case NODE_PROTOCOL_INFO:
                        System.out.println(String.format("Node protocol info\n" +
                                "\tnode id: %d\n" +
                                "\ttype: %s",
                                notification.getNodeId(),
                                manager.getNodeType(notification.getHomeId(), notification.getNodeId())
                        ));
                        break;
                    case VALUE_ADDED:
                        System.out.println(String.format("Value added\n" +
                                "\tnode id: %d\n" +
                                "\tcommand class: %d\n" +
                                "\tinstance: %d\n" +
                                "\tindex: %d\n" +
                                "\tgenre: %s\n" +
                                "\ttype: %s\n" +
                                "\tlabel: %s\n" +
                                "\tvalue: %s",
                                notification.getNodeId(),
                                notification.getValueId().getCommandClassId(),
                                notification.getValueId().getInstance(),
                                notification.getValueId().getIndex(),
                                notification.getValueId().getGenre().name(),
                                notification.getValueId().getType().name(),
                                manager.getValueLabel(notification.getValueId()),
                                getValue(notification.getValueId())
                        ));
                        break;
                    case VALUE_REMOVED:
                        System.out.println(String.format("Value removed\n" +
                                "\tnode id: %d\n" +
                                "\tcommand class: %d\n" +
                                "\tinstance: %d\n" +
                                "\tindex: %d",
                                notification.getNodeId(),
                                notification.getValueId().getCommandClassId(),
                                notification.getValueId().getInstance(),
                                notification.getValueId().getIndex()
                        ));
                        break;
                    case VALUE_CHANGED:
                        System.out.println(String.format("Value changed\n" +
                                "\tnode id: %d\n" +
                                "\tcommand class: %d\n" +
                                "\tinstance: %d\n" +
                                "\tindex: %d\n" +
                                "\tvalue: %s",
                                notification.getNodeId(),
                                notification.getValueId().getCommandClassId(),
                                notification.getValueId().getInstance(),
                                notification.getValueId().getIndex(),
                                getValue(notification.getValueId())
                        ));
                        break;
                    case VALUE_REFRESHED:
                        System.out.println(String.format("Value refreshed\n" +
                                "\tnode id: %d\n" +
                                "\tcommand class: %d\n" +
                                "\tinstance: %d\n" +
                                "\tindex: %d" +
                                "\tvalue: %s",
                                notification.getNodeId(),
                                notification.getValueId().getCommandClassId(),
                                notification.getValueId().getInstance(),
                                notification.getValueId().getIndex(),
                                getValue(notification.getValueId())
                        ));
                        break;
                    case GROUP:
                        System.out.println(String.format("Group\n" +
                                "\tnode id: %d\n" +
                                "\tgroup id: %d",
                                notification.getNodeId(),
                                notification.getGroupIdx()
                        ));
                        break;

                    case SCENE_EVENT:
                        System.out.println(String.format("Scene event\n" +
                                "\tscene id: %d",
                                notification.getSceneId()
                        ));
                        break;
                    case CREATE_BUTTON:
                        System.out.println(String.format("Button create\n" +
                                "\tbutton id: %d",
                                notification.getButtonId()
                        ));
                        break;
                    case DELETE_BUTTON:
                        System.out.println(String.format("Button delete\n" +
                                "\tbutton id: %d",
                                notification.getButtonId()
                        ));
                        break;
                    case BUTTON_ON:
                        System.out.println(String.format("Button on\n" +
                                "\tbutton id: %d",
                                notification.getButtonId()
                        ));
                        break;
                    case BUTTON_OFF:
                        System.out.println(String.format("Button off\n" +
                                "\tbutton id: %d",
                                notification.getButtonId()
                        ));
                        break;
                    case NOTIFICATION:
                        System.out.println("Notification");
                        break;
                    default:
                        System.out.println(notification.getType().name());
                        break;
                }
            }
        };
        manager.addWatcher(watcher, null);

        final String controllerPort = args[1];

        manager.addDriver(controllerPort);

        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;
        do {
            line = br.readLine();
            if (!ready || line == null) {
                continue;
            }

            switch (line) {
                case "on":
                    manager.switchAllOn(homeId);
                    break;
                case "off":
                    manager.switchAllOff(homeId);
                    break;
            }
        } while(line != null && !line.equals("q"));


        br.close();

        manager.removeWatcher(watcher, null);
        manager.removeDriver(controllerPort);
        Manager.destroy();
	    Options.destroy();
    }

    private static Object getValue(ValueId valueId) {
        switch (valueId.getType()) {
            case BOOL:
                AtomicReference<Boolean> b = new AtomicReference<>();
                Manager.get().getValueAsBool(valueId, b);
                return b.get();
            case BYTE:
                AtomicReference<Short> bb = new AtomicReference<>();
                Manager.get().getValueAsByte(valueId, bb);
                return bb.get();
            case DECIMAL:
                AtomicReference<Float> f = new AtomicReference<>();
                Manager.get().getValueAsFloat(valueId, f);
                return f.get();
            case INT:
                AtomicReference<Integer> i = new AtomicReference<>();
                Manager.get().getValueAsInt(valueId, i);
                return i.get();
            case LIST:
                return null;
            case SCHEDULE:
                return null;
            case SHORT:
                AtomicReference<Short> s = new AtomicReference<>();
                Manager.get().getValueAsShort(valueId, s);
                return s.get();
            case STRING:
                AtomicReference<String> ss = new AtomicReference<>();
                Manager.get().getValueAsString(valueId, ss);
                return ss.get();
            case BUTTON:
                return null;
            case RAW:
                AtomicReference<short[]> sss = new AtomicReference<>();
                Manager.get().getValueAsRaw(valueId, sss);
                return sss.get();
            default:
                return null;
        }
    }
}
