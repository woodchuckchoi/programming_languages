import { Controller, Get, Post, Put, Delete, Body, Param } from '@nestjs/common';
import { CreateItemDto } from './dto/create-item.dto';
import { ItemsService } from './items.service';
import { Item } from './interfaces/item.interface';

@Controller('items')
export class ItemsController {
  constructor(private readonly itemsService: ItemsService) {}

  @Get()
  findAll(): Promise<Item[]> {
      return this.itemsService.findAll();
  }

//   @Get(':id')
//   findOne(@Param() param): string {
//       return `Item ${param.id}`
//   }

  @Get(':id')
  findOne(@Param('id') id): Promise<Item> {
      return this.itemsService.findOne(id);
  }

//   @Get(':id/:desc')
//   doSomething(@Param('id') id, @Param('desc') desc): string {
//       return `${id} ${desc}`
//   }

  @Post()
  create(@Body() createItemDto: CreateItemDto): Promise<Item> {
    return this.itemsService.create(createItemDto);
  }

  @Delete(':id')
  delete(@Param('id') id): Promise<Item> {
    return this.itemsService.delete(id);
  }

  @Put(':id')
  update(@Body() updateItemDto: CreateItemDto, @Param('id') id): Promise<Item> {
    return this.itemsService.update(id, updateItemDto);
  }
}