import { Injectable } from '@nestjs/common';

@Injectable()
export class AppService {
  private readonly start : number; 

  constructor() {
    this.start = Date.now();
  }

  healthCheck(): object {
    const now = Date.now();
    
    return {
      status: 'OK',
      uptime: Number((now - this.start)/1000).toFixed(0),
    };
  }
}
