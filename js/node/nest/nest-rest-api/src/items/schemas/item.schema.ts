import { Prop, Schema, SchemaFactory } from '@nestjs/mongoose';
import { Document } from 'mongoose';

@Schema()
class Item {
  @Prop({required: false})
  id: string;

  @Prop()
  name: string;

  @Prop()
  description: string;

  @Prop()
  qty: number;
}

export type ItemDocument = Item & Document;

export const ItemSchema = SchemaFactory.createForClass(Item);