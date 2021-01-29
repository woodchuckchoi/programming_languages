import { EventEmitter } from 'events';
import * as uuid from 'uuid';

class Logger extends EventEmitter {
    log(msg) {
        this.emit('message', { id: uuid.v4(), msg: msg});
    }
}

export { Logger };